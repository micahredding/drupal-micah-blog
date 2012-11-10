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
  $context->tag = '';
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
    'block' => array(
      'blocks' => array(
        'mrblocks-section-photo-life' => array(
          'module' => 'mrblocks',
          'delta' => 'section-photo-life',
          'region' => 'header',
          'weight' => '-22',
        ),
        'mrblocks-section-title-life' => array(
          'module' => 'mrblocks',
          'delta' => 'section-title-life',
          'region' => 'header',
          'weight' => '-21',
        ),
        'block-8' => array(
          'module' => 'block',
          'delta' => '8',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['life'] = $context;

  return $export;
}
