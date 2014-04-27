<?php

$plugin = array(
  'title' => t('Forward link'),
  'description' => t('A forward link for this node.'),
  'category' => t('Node'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'render callback' => 'forward_panels_node_render',
);

function forward_panels_node_render($subtype, $conf, $panel_args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }
  if (!user_access('access forward')) {
    return;
  }

  // Get a shortcut to the node.
  $entity_type = 'node';
  $node = $context->data;
  list($id, $vid, $bundle) = entity_extract_ids($entity_type, $node);
  if (!$id) {
    return;
  }

  if (variable_get('forward_entity_' . $entity_type, FALSE) && variable_get('forward_'.$entity_type.'_'.$bundle, FALSE)) {
    // Build the link
    $widget_code = array(
      '#markup' => theme('forward_link', array('entity_type' => $entity_type, 'entity' => $node)),
    );

    // Build the content type block.
    $block = new stdClass();
    $block->module = 'forward';
    $block->content = $widget_code;
    $block->delta = $node->nid;

    return $block;
  }
}
