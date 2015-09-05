(function ($) {

/**
 * Attaches the autocomplete behavior to all required fields.
 */
Drupal.behaviors.stanford_search_api_results = {
  attach: function (context, settings) {

    // Set the focus to the first search element if there has been a filter
    // ----------------------------------------------------------------

    $("#content-body .view-header", context).attr("tabIndex", 0);
    $("#content-body .view-header", context).css("outline", 0);
    $("#content-body .view-header:first-child", context).focus();

  }
};

})(jQuery);