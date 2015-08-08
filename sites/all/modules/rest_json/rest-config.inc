<?php

global $rest_conf; $rest_conf = array(

	'rest_prefix' => 'rest', // rest prefix, e.g. "rest" to access "rest/event/list"
	
#	'cache_bin' => 'cache_page', // Drupal bin to store list/* and node/* caching, use '' to disable cache
	'cache_bin' => '', // FIXME: abilitare in prod
	
	'image_style' => 'app_images', // image style for pictures
	
	'base_node_fields' => array( // base node fields to print, besides custom field_*
		'nid' => 'nid', 
		'tnid' => 'tnid', 
		'type' => 'type', 
		'title_field' => 'display_name',
		'changed' => 'timestamp', 
	),

	'base_user_fields' => array( // user fields to print
		'uid' => 'uid', 
		'name' => 'name', 
		'mail' => 'mail', 
		'language' => 'language',
	), 

	'base_comment_fields' => array( // comment fields to print
		'cid' => 'cid', 
		'pid' => 'pid', 
		'nid' => 'nid', 
		'uid' => 'uid', 
		'subject' => 'subject', 
		'changed' => 'timestamp', 
		'language' => 'language',
		'name' => 'username',
		'node_type' => 'node_type',
		'comment_body' => 'comment',
	), 
);

