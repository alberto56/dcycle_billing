<?php

/**
 * @file
 * Drush integration for the simpletest_turbo module.
 */

/**
 * Implements hook_drush_command().
 */
function simpletest_turbo_drush_command() {
  $items['turbo-reset'] = array(
    'description' => dt('Resets the Simpletest Turbo cache. Call this before running your tests if your code has changed.'),
    'aliases' => array('str'),
  );
  return $items;
}

/**
 * Callback: Resets Simpletest Turbo
 */
function drush_simpletest_turbo_turbo_reset() {
  simpletest_turbo_start();
  drush_log(dt('Simpletest Turbo\'s cache has been reset. You can now run your tests normally. See Simpletest Turbo\'s README.txt for more information on how to make your tests turbo-aware.'), 'ok');
}
