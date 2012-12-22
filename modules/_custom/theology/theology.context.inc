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
  $context->tag = 'category';
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
    'theme' => array(
      'title' => 'Christianity Against Religion',
      'subtitle' => '',
    ),
    'theme_html' => array(
      'class' => 'theology',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('category');
  $export['theology'] = $context;

  return $export;
}
