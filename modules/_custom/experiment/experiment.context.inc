<?php
/**
 * @file
 * experiment.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function experiment_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'experiment';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        2548 => 2548,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'experiment' => 'experiment',
        'category/experiment' => 'category/experiment',
        'experiment/*' => 'experiment/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-16' => array(
          'module' => 'block',
          'delta' => 16,
          'region' => 'topbar',
          'weight' => '-10',
        ),
        'block-23' => array(
          'module' => 'block',
          'delta' => 23,
          'region' => 'header',
          'weight' => '-10',
        ),
        'block-18' => array(
          'module' => 'block',
          'delta' => 18,
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['experiment'] = $context;

  return $export;
}
