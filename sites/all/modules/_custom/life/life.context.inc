<?php
/**
 * @file
 * life.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function life_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'life';
  $context->description = '';
  $context->tag = 'category';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~theology' => '~theology',
        '~front' => '~front',
        '~experiment' => '~experiment',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'life',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('category');
  $export['life'] = $context;

  return $export;
}
