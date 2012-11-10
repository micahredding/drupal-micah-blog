<?php

function micah_preprocess_page(&$vars,$hook) {

  //get all menu's
  $menus = array();
  $menus = menu_get_menus($all = TRUE);
  
  //create var for every menu so we can use it in our page.tpl.php
  foreach($menus as $key => $value){
      $var = str_replace('-','_',$key);
      $vars[$var] = menu_tree($key);
  } 
}