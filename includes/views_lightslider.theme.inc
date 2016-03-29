<?php

/**
 * @file
 * views_lightslider theme functions.
 */

/**
 * Returns HTML for an views_lightslider image field formatter.
 *
 */
function theme_views_lightslider_image_formatter($variables) {
  $item_list = array();
  $items = $variables['items'];
  $settings = $variables['display_settings'];

  foreach ($items as $item) {
    foreach ($settings['image_styles'] as $image_style => $label) {
      // Fetch path for content.
      if ($style_name = $settings['image_styles'][$image_style]) {
        // Create url for image style.
        $paths[$image_style] = file_create_url(image_style_url($style_name,
                $item['uri']));
      }
      else {
        // Create url for original image.
        $paths[$image_style] = file_create_url($item['uri']);
      }
    }
    // Store paths in array.
    $item_list[] = $paths;
  }

  // Render light slider item list.
  $unique_id = uniqid();
  $views_lightslider_item_list = array(
    '#theme' => 'views_lightslider_item_list',
    '#items' => $item_list,
    '#unique_id' => $unique_id,
  );

  // Add libraries and settings.
  $option_set = _views_lightslider_build_option_set($options);
  views_lightslider_add($unique_id, $option_set);

  // Render the complete light slider markyp.
  return drupal_render($views_lightslider_item_list);
}