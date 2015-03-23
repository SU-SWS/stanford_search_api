<?php
/**
 * @file
 */

class stanford_search_api_handler_field_entity extends entity_views_handler_field_entity {

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
   * [render_entity_link description]
   * @param  [type] $entity [description]
   * @param  [type] $values [description]
   * @return [type]         [description]
   */
  public function render_entity_link($entity, $values) {
    $type = $this->field_entity_type;
    $options = $this->options;

    // If we have a filter lets hide values.
    if (!empty($options['filter_values'])) {
      $filters = explode(",", $options['filter_values']);
      if (in_array($type, $filters)) {
        return '';
      }
    }

    if (!is_object($entity) && isset($entity) && $entity !== FALSE) {
      $entity = entity_load_single($type, $entity);
    }

    if (!$entity) {
      return '';
    }

    $render = $this->render_single_value($entity, $values);

    if ($this->options['link_as_facet']) {
      $query = $_GET;
      unset($query['q']);

      // Check for the facets.
      $query['f'] = isset($query['f']) ? $query['f'] : array();

      // Add the type in.
      if (!in_array($this->real_field . ":" . $entity->tid, $query['f'])) {
        $query['f'][] = $this->real_field . ":" . $entity->tid;
      }

      return l($render, "search/content", array(
        'html' => TRUE,
        'query' => $query,
      ));

    }

    if (!$this->options['link_to_entity'] || $this->options['display'] == 'view') {
      return $render;
    }

    if (is_object($entity) && ($url = entity_uri($type, $entity))) {
      return l($render, $url['path'], array('html' => TRUE) + $url['options']);
    }

    return $render;
  }


}
