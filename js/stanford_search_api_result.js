(function ($) {

/**
 * Attaches the autocomplete behavior to all required fields.
 */
Drupal.behaviors.stanford_search_api = {
  attach: function (context, settings) {

    // Set the focus to the first search element if there has been a filter
    // ----------------------------------------------------------------

    $("#content-body .view-header").attr("tabIndex", 0);
    $("#content-body .view-header").css("outline", 0);
    $("#content-body .views-row-first .view-header:first-child").focus();

  }
};

})(jQuery);