<?php

$plugin = array(
  'title' => t('Forward link'),
  'description' => t('A forward link for this term.'),
  'category' => t('Taxonomy term'),
  'required context' => new ctools_context_required(t('Taxonomy term'), 'taxonomy_term'),
  'render callback' => 'forward_panels_term_render',
);

function forward_panels_term_render($subtype, $conf, $panel_args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }
  if (!user_access('access forward')) {
    return;
  }

  // Get a shortcut to the term.
  $entity_type = 'taxonomy_term';
  $term = $context->data;
  list($id, $vid, $bundle) = entity_extract_ids($entity_type, $term);
  if (!$id) {
    return;
  }

  if (variable_get('forward_entity_' . $entity_type, FALSE) && variable_get('forward_'.$entity_type.'_'.$bundle, FALSE)) {
    // Build the link
    $widget_code = array(
      '#markup' => theme('forward_link', array('entity_type' => $entity_type, 'entity' => $term)),
    );

    // Build the content type block.
    $block = new stdClass();
    $block->module = 'forward';
    $block->content = $widget_code;
    $block->delta = $term->tid;

    return $block;
  }
}
