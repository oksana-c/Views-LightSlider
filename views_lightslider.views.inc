<?php
/**
 * @file
 * Provide the views lightslider plugin definition.
 */
function views_lightslider_views_plugins() {
  return array(
    'module' => 'views_lightslider',
    'style' => array(
      'views_lightslider' => array(
        'title' => t('Views LightSlider'),
        'theme' => 'views_lightslider_view',
        'help' => t('Display a view with LightSlider.'),
        'handler' => 'views_lightslider_style_plugin',
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
    'row' => array(
      'lightsliderfields' => array(
        'title' => t('Views LightSlider'),
        'help' => t('Select the fields to display in LightSlider Style.'),
        'handler' => 'views_lightslider_plugin_row_lightsliderfields',
        'theme' => 'views_lightslider_view_lightsliderfields',
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}
