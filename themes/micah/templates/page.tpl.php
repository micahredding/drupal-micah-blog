<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 */
?>
  <div id="header-image">
    <img src="<?php print $base_path . path_to_theme(); ?>/images/sandy_flare_desktop.jpg" />
  </div>

  <header id="header">
    <div id="site-name">
      <a href="<?php print $base_path; ?>">
        <span class="text-logo">m/r</span><span class="text-text">micah/redding</span>
      </a>
    </div>
    <ul>
      <li><a href="http://micahredding.com/blog/life">Life on the Curve</a></li>      
      <li><a href="http://micahredding.com/blog/theology">Christianity Against Religion</a></li>      
      <li><a href="http://micahredding.com/blog/transhumanism">The Singularity &amp; Transhumanism</a></li>      
      <li><a href="http://micahredding.com/blog/2012/01/15/micah-redding">About Micah Redding</a></li>
      <li><a href="http://twitter.com/micahtredding">Twitter</a></li>
    </ul>
  </header>

  <nav class="site-nav">
  <?php if($page['header']): ?>
      <?php print render($page['header']); ?>
  <?php endif; ?>
  </nav>

  <div id="page">

    <?php print $messages; ?>

    <?php if ($page['highlighted']): ?>
      <div id="highlighted">
        <?php print render($page['highlighted']); ?>
      </div>
    <?php endif; ?>
        
    <div id="main-wrapper"><div id="main" class="clearfix">

      <div id="content" class="column">
        <a id="main-content"></a>
        <div class="contextual-links-region">        
          <?php print render($title_prefix); ?>
          <?php if ($title): ?><h1 class="page title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
          <?php print render($title_suffix); ?>
          <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
          <?php print render($page['help']); ?>
          <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
          <?php print render($page['content']); ?>
          <?php print $feed_icons; ?>
        </div>
      </div> <!-- /#content -->

    </div></div> <!-- /#main, /#main-wrapper -->


  </div> <!-- /#page, /#page-wrapper -->

  <?php if ($page['sidebar_first']): ?>
    <div id="sidebar-first" class="column sidebar"><div class="section">
      <?php print render($page['sidebar_first']); ?>
    </div></div> <!-- /.section, /#sidebar-first -->
  <?php endif; ?>

  <?php if ($page['sidebar_second']): ?>
    <div id="sidebar-second" class="column sidebar"><div class="section">
      <?php print render($page['sidebar_second']); ?>
    </div></div> <!-- /.section, /#sidebar-second -->
  <?php endif; ?>

  <footer>
    <div class="internal">
      <?php print render($page['footer']); ?>
      <div class="google-plus">
        <a href="http://micahredding.com/blog/rss.xml">RSS</a>, 
        <a href="https://plus.google.com/110800681150805455169?rel=author">Google +</a> 
      </div>
    </div>
  </footer>

