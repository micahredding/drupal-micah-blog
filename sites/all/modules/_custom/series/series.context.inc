<?php
/**
 * @file
 * series.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function series_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'series';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        2536 => 2536,
        2537 => 2537,
        2538 => 2538,
        2539 => 2539,
        2549 => 2549,
        2556 => 2556,
        2557 => 2557,
        2559 => 2559,
        2560 => 2560,
        2561 => 2561,
        2562 => 2562,
        2563 => 2563,
        2565 => 2565,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-series-block' => array(
          'module' => 'views',
          'delta' => 'series-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['series'] = $context;

  return $export;
}
