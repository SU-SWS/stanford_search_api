(function ($) {

/**
 * Attaches the autocomplete behavior to all required fields.
 */
Drupal.behaviors.stanford_search_api = {
  attach: function (context, settings) {

    // Change the autocomplete search box container role to 'search'
    // ----------------------------------------------------------------

    var input = $("input[role='combobox'].form-autocomplete, .btn-search", context);
    if (!input.length) {
      return;
    }
    var parent = input.parent();
    parent.attr("role", "search");

    // ----------------------------------------------------------------

    // Set the focus to the first search element if there has been a filter
    // ----------------------------------------------------------------

    $("#content-body .view-header").attr("tabIndex", 0);
    $("#content-body .view-header").css("outline", 0);
    $("#content-body .view-header:first-child").focus();

  }
};

})(jQuery);
