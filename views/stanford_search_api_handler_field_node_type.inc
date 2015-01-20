<?php
/**
 * @file
 */

class stanford_search_api_handler_field_node_type extends entity_views_handler_field_options {

  /**
   * [option_definition description]
   * @return [type] [description]
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['link_as_facet'] = array('default' => FALSE, 'bool' => TRUE);

    return $options;
  }

   /**
   * Provide machine_name option for to node type display.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['link_as_facet'] = array(
      '#title' => t('Link as a facet'),
      '#description' => t('Output this link as a facet link.'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_as_facet']),
    );
  }

  /**
   * [render description]
   * @param  [type] $values [description]
   * @return [type]         [description]
   */
  function render($values) {
    $output = "";
    $options = $this->options;
    $value = $this->get_value($values);

    // Add the search request back.
    // $query = array("search_api_views_fulltext" => check_plain($_REQUEST['search_api_views_fulltext']));
    $query = $_REQUEST;

    // Check for the facets.
    if (!isset($query['f']) || !is_array($query['f'])) {
      $query['f'][] = "type:" . $values->entity->type;
    }
    else {
      // Look for the type facet.
      array_walk($query['f'], "stanford_search_api_find_facet_type_index", $values->entity->type);
    }

    // Change the link to a facet.
    if ($options['link_as_facet']) {
      $output = l($value, "search/content", array("query" => $query));
    }
    else {
      $output = parent::render($values);
    }

    return $output;
  }


}
