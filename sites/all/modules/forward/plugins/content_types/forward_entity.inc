<?php

$plugin = array(
  'title' => t('Forward link'),
  'description' => t('A forward link for this entity.'),
  'category' => t('Entity'),
  'required context' => new ctools_context_required(t('Entity'), 'entity'),
  'render callback' => 'forward_panels_entity_render',
);

function forward_panels_entity_render($subtype, $conf, $panel_args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }
  if (!user_access('access forward')) {
    return;
  }

  // Get the entity info
  $entity_type = str_replace('entity:', '', $context->plugin);
  $entity = $context->data;
  list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);
  if (!$id) {
    return;
  }

  if (variable_get('forward_entity_' . $entity_type, FALSE) && variable_get('forward_'.$entity_type.'_'.$bundle, FALSE)) {
    // Build the link
    $widget_code = array(
      '#markup' => theme('forward_link', array('entity_type' => $entity_type, 'entity' => $entity)),
    );

    // Build the content type block.
    $block = new stdClass();
    $block->module = 'forward';
    $block->content = $widget_code;
    $block->delta = $id;

    return $block;
  }
}
