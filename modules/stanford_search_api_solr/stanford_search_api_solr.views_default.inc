<?php

/**
 * Implements hook_views_default_views()
 * @return [type] [description]
 */
function stanford_search_api_solr_views_default_views() {
  module_load_include("inc", "stanford_search_api", "stanford_search_api.util");
  $views = stanford_search_api_get_default_views();

  $export = array();

  $view = $views['search_page'];
  $view->name = 'search_solr_nodes';
  $view->description = 'Search API SOLR Nodes Search Page';
  $view->base_table = 'search_api_index_solr_nodes_now';
  $view->human_name = 'Search SOLR Nodes';

  $export['search_db_nodes'] = $view;

  return $export;
}
