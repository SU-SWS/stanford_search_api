<?php
/**
 * @file
 * stanford_search_api_db_facet_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_search_api_solr_facet_context_context_default_contexts() {
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
        'facetapi-KTKqAhH8zkkDCMWAf1Yi3zoMRr8WPfhq' => array(
          'module' => 'facetapi',
          'delta' => 'KTKqAhH8zkkDCMWAf1Yi3zoMRr8WPfhq',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-0jT33lTbH1jmTzk52H3GRWVN0ZHZWvQ2' => array(
          'module' => 'facetapi',
          'delta' => '0jT33lTbH1jmTzk52H3GRWVN0ZHZWvQ2',
          'region' => 'sidebar_first',
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
