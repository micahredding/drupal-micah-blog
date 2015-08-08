<?php

/**
 * Prints a JSON list of content, filtered by node type.
 *
 * Endpoint: /<rest_prefix>/list/<content-type>
 */
function page_rest_json_list($type, $filter_nid=0) {
	global $rest_conf, $language;
	
	// Check cached requests
	if ($nodes = rest_json_cache_get()) {
		rest_json_response(TRUE, 'node', $nodes, '', TRUE);
	}
	
	// Check limits
	if (!($offset = request_param('offset'))) $offset = 0;
	if (!($limit = request_param('limit'))) $limit = 20;
	
	// Set filters
	$filter_sql = '';
	$tokens = array(':type'=>$type, ':lang'=>$language->language);
	if ($filter_nid) {
		$filter_sql = "AND node.nid = :nid";
		$tokens[':nid'] = $filter_nid;
	}

	// Select elements
	$sql = "SELECT node.nid FROM {node} node"
		." LEFT JOIN (SELECT tnode.nid AS nid, tnode.tnid AS tnid, tnode.status AS status, tnode.language AS language FROM {node} tnode WHERE tnode.language = 'en' AND tnode.status = 1) tnode"
		." ON node.tnid = tnode.tnid AND node.tnid != 0"
		." WHERE ( node.status = '1' AND (node.tnid = 0 OR node.language = :lang OR (node.nid = node.tnid AND tnode.nid IS NULL)) AND node.type = :type $filter_sql )"
		." LIMIT $limit OFFSET $offset";
	
	// All nodes by type
	$nodes = array(); $result = db_query($sql, $tokens);
	foreach ($result as $r) {
		// Get node
		$node = rest_json_node($r->nid);
		
		// Let other modules attach more content
		drupal_alter('rest_json_node_list', $node);
	
		$nodes[] = $node;
	}
	
	// Nodes list
	rest_json_cache_set($nodes);
	rest_json_response(TRUE, 'node', $nodes);
} // rest_json_list

/**
 * Prints a JSON node, selected by nid.
 *
 * Endpoint: /<rest_prefix>/node/<nid>
 */
function page_rest_json_node($nid) {
	// Check cached requests
	if ($node = rest_json_cache_get()) {
		rest_json_response(TRUE, 'node', $node, '', TRUE);
	}

	// Single node
	$node = rest_json_node($nid);
	
	// Check that node exists
	if (!$node) rest_json_response(FALSE, 'node', $node, "Node $nid does not exist");
	
	// Let other modules attach more content
	drupal_alter('rest_json_node', $node);
	
	// Node
	rest_json_cache_set($node);
	rest_json_response(TRUE, 'node', $node);
} // rest_json_node

/**
 * Get JSON of single node.
 */
function rest_json_node($node_or_nid) {
	global $rest_conf;
	
	$j = new stdClass;
	
	$node = is_numeric($node_or_nid) ? node_load($node_or_nid) : $node_or_nid;
	if (empty($node)) return NULL;
	
	// See https://www.drupal.org/documentation/entity-metadata-wrappers
	$nodew = entity_metadata_wrapper('node', $node);
	
	// Base fields
	foreach ($rest_conf['base_node_fields'] as $field => $name) {
		$j->{$name} = rest_json_value($nodew, $field);
	}
	
	// Custom fields
	$prefix = 'field_';
	foreach (array_keys(get_object_vars($node)) as $field) {
		// Filter custom fields only
		if (strrpos($field, $prefix, -strlen($field)) !== FALSE && isset($nodew->{$field})) {
			$name = substr($field, strlen($prefix));
			$j->{$name} = rest_json_value($nodew, $field);
		}
	}
	
	return $j;
} // rest_json_node

/**
 * Add a new node.
 *
 * Endpoint: /<rest_prefix>/add/node/<content-type>
 */
function page_rest_json_add_node($type) {
	global $user, $language;
	
	// Check auth
	check_user_auth('create ' . $type . ' content');
	
	// Check params
	// FIXME: how to check mandatory params?
	$title = request_param('title');
	$body = request_param('body');
	$fields = request_param('fields');
	
	// Create node
	$node = entity_create('node', array(
		'type' => $type,
		'uid' => $user->uid,
		'language' => $language->language,
	));
	$nodew = entity_metadata_wrapper('node', $node);
	if ($title) $nodew->title = $title;
	if ($body) $nodew->body = array('value'=>$body, 'format'=>'plain_text');
	
	// Add custom fields
	foreach ($fields as $k => $v) rest_json_value_set($nodew, 'field_'.$k, $v);
	
	// Let other modules attach more content
	drupal_alter('rest_json_node_add', $nodew);
	
	// Save node
#	d($nodew->value());
	$nodew->save();
	
	rest_json_response(TRUE, 'node', rest_json_node($nodew->value()));
} // page_rest_json_add_node

