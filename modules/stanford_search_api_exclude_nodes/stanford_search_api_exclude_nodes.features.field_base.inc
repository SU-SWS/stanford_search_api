<?php
/**
 * @file
 * stanford_search_api_exclude_nodes.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function stanford_search_api_exclude_nodes_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_s_apachesolr_index'
  $field_bases['field_s_apachesolr_index'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_apachesolr_index',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Index',
        1 => 'Do Not Index',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
