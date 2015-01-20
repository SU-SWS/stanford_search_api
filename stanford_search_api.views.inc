<?php
/**
 * @file
 *
 */

/**
 * [stanford_search_api_views_data description]
 * @return [type] [description]
 */
function stanford_search_api_views_data_alter(&$data) {

  // Change the field handler to ours.
  // $data['node']['type']['field']['handler'] = "stanford_search_api_handler_field_node_type";
  // $data['entity_node']['type']['field']['handler'] = "stanford_search_api_handler_field_node_type";

  $indexes = search_api_index_load_multiple(FALSE);

  foreach ($indexes as $index_name => $values) {
    $views_name = "search_api_index_" . $index_name;
    if (isset($data[$views_name])) {
      $data[$views_name]['type']['field']['handler'] = "stanford_search_api_handler_field_node_type";
      $data[$views_name]['field_tags']['field']['handler'] = "stanford_search_api_handler_field_entity";
    }
  }

}
