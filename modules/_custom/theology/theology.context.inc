<?php
/**
 * @file
 * theology.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function theology_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'theology';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        2521 => 2521,
        2545 => 2545,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'views' => array(
      'values' => array(
        'theology' => 'theology',
        'theology:page' => 'theology:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mrblocks-section-title-theology' => array(
          'module' => 'mrblocks',
          'delta' => 'section-title-theology',
          'region' => 'header',
          'weight' => '-10',
        ),
        'mrblocks-section-photo-theology' => array(
          'module' => 'mrblocks',
          'delta' => 'section-photo-theology',
          'region' => 'header',
          'weight' => '-10',
        ),
        'block-19' => array(
          'module' => 'block',
          'delta' => '19',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'theology',
    ),
  );
  $context->condition_mode = 0;
  $export['theology'] = $context;

  return $export;
}
