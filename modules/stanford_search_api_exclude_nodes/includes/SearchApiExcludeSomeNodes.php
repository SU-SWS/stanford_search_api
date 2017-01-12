<?php

/**
 * @file
 * Contains class used for excluding entity.
 */

/**
 * SearchApiExcludeSomeNodes provides mechanism for not indexing nodes.
 */
class SearchApiExcludeSomeNodes extends SearchApiAbstractAlterCallback {

  public function supportsIndex(SearchApiIndex $index) {
    return $index->getEntityType() === 'node';
  }

  public function alterItems(array &$items) {
    foreach ($items as $k => $item) {
      $wrapper = entity_metadata_wrapper('node', $item);
      if(isset($wrapper->field_s_apachesolr_index) && $wrapper->field_s_apachesolr_index->value() == '1') {
        unset($items[$k]);
      }
    }
  }

}
