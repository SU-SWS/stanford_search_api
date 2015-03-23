<?php
/**
 * @file
 * stanford_search_api_db_facet_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_search_api_db_facet_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'stanford_search_api_facet';
  $context->description = 'Places facets on the search api views pages';
  $context->tag = 'Search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search/content*' => 'search/content*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-SPQQU6tD1IoqvO2yXTgzRfRH65T1OfN7' => array(
          'module' => 'facetapi',
          'delta' => 'SPQQU6tD1IoqvO2yXTgzRfRH65T1OfN7',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'facetapi-LIXsZqdtKYz1TuYBcl5Uh0jsBG7KIOPL' => array(
          'module' => 'facetapi',
          'delta' => 'LIXsZqdtKYz1TuYBcl5Uh0jsBG7KIOPL',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Places facets on the search api views pages');
  t('Search');
  $export['stanford_search_api_facet'] = $context;

  return $export;
}
