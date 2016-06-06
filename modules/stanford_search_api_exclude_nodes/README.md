#[Stanford Search API Exclude Nodes](https://github.com/SU-SWS/stanford_search_api/modules/stanford_search_api_exclude_nodes)
##### Version: 7.x-1.x

Maintainers: [boznik](https://github.com/boznik)

[Changelog.txt](CHANGELOG.txt)

The Stanford Search API Exclude Nodes module is used to exclude selected nodes from being indexed with apache solr.

This will appear as an option in the UI of Search API, in the Data alterations section. Select the checkbox 'Exclude some nodes'.

You will need to add the field field_s_apachesolr_index to the content type you want to be able to exclude nodes of that type.

You can then choose 'Do Not Index' from the select dropdown.

Previously indexed nodes will not be removed from the index. You will need to clear the index and then re-index if a node you have selected to not be indexed has already been added.

Installation
---

Install this module like any other module. [See Drupal Documentation](https://drupal.org/documentation/install/modules-themes/modules-7)

Configuration
---

Nothing special needed.

Troubleshooting
---

If you are experiencing issues with this module try reverting the feature first. If you are still experiencing issues try posting an issue on the GitHub issues page.

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)
