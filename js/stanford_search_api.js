(function ($) {

/**
 * Attaches the autocomplete behavior to all required fields.
 */
Drupal.behaviors.stanford_search_api = {
  attach: function (context, settings) {

    // Change the autocomplete search box container role to 'search'
    // ----------------------------------------------------------------

    var input = $("input[role='combobox'].form-autocomplete");
    if (!input.length) {
      return;
    }
    var parent = input.parent();
    parent.attr("role", "search");

    // ----------------------------------------------------------------

  }
};

})(jQuery);
