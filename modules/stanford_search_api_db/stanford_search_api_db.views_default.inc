<?php

/**
 * Implements hook_views_default_views()
 * @return [type] [description]
 */
function stanford_search_api_db_views_default_views() {
  module_load_include("inc", "stanford_search_api", "stanford_search_api.util");
  $views = stanford_search_api_get_default_views();

  $export = array();

  $view = $views['search_page'];
  $view->name = 'search_db_nodes';
  $view->description = 'Search API Search DB Nodes Search Page';
  $view->base_table = 'search_api_index_nodes_now';
  $view->human_name = 'Search DB Nodes';

  $export['search_db_nodes'] = $view;

  return $export;
}
