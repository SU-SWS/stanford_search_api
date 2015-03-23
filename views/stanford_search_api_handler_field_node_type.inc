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
    $options['filter_values'] = array('default' => "");

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

    $form['filter_values'] = array(
      '#title' => t("Hide field if equal to values"),
      '#descrtiption' => t("A comma separated list of values to compare against the result value. If values match, do not display the result."),
      '#type' => 'textfield',
      '#default_value' => !empty($this->options['filter_values']) ? $this->options['filter_values'] : "",
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
    $type = $values->_entity_properties['type'];

    // If we have a filter lets hide values.
    if (!empty($options['filter_values'])) {
      $filters = explode(",", $options['filter_values']);
      if (in_array($type, $filters)) {
        return '';
      }
    }

    // Add the search request back.
    $query = $_GET;
    unset($query['q']);

    // Check for the facets.
    $query['f'] = isset($query['f']) ? $query['f'] : array();

    // Add the type in.
    if (!in_array("type:" . $type, $query['f'])) {
      $query['f'][] = "type:" . $type;
    }

    // Change the link to a facet.
    if ($options['link_as_facet']) {
      if (!empty($options['format_name'])) {
        $names = node_type_get_names();
        $value = $names[$value];
      }
      $output = l($value, "search/content", array("query" => $query, "attributes" => array('class' => array($options['element_class']))));
    }
    else {
      $output = parent::render($values);
    }

    return $output;
  }


}
