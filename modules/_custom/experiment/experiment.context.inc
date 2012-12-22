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
  $context->tag = 'category';
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
    'theme' => array(
      'title' => 'Notes & Experiments',
      'subtitle' => '',
    ),
    'theme_html' => array(
      'class' => 'experiment',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('category');
  $export['experiment'] = $context;

  return $export;
}
