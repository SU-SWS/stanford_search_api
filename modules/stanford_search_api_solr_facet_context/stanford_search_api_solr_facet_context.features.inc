<?php
/**
 * @file
 * stanford_search_api_db_facet_context.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_search_api_solr_facet_context_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
