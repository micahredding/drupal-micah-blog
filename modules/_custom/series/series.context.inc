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
  $context->conditions = array();
  $context->reactions = array();
  $context->condition_mode = 0;
  $export['series'] = $context;

  return $export;
}
