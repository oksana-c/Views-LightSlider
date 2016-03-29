<?php

/**
 * @file
 * Contains all hooks and related methods for the views_lightslider_formatter field
 * formatter.
 */

/**
 * Implements hook_field_formatter_info().
 */
function views_lightslider_field_formatter_info() {
  return array(
    'views_lightslider' => array(
      'label' => t('views_lightslider'),
      'field types' => array('image'),
      'settings' => array(
        'image_styles' => array(
          'views_lightslider_image_style' => NULL,
          'views_lightslider_image_thumb_style' => NULL,
        ),
      ),
    ),
  );
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function views_lightslider_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $image_styles = image_style_options(FALSE);

  $element['image_styles']['views_lightslider_image_style'] = array(
    '#title' => t('views_lightslider image style'),
    '#type' => 'select',
    '#default_value' => $settings['image_styles']['views_lightslider_image_style'],
    '#empty_option' => t('None (original image)'),
    '#options' => $image_styles,
    '#description' => t('Light gallery image style.'),
  );

  $element['image_styles']['views_lightslider_image_thumb_style'] = array(
    '#title' => t('Content image style'),
    '#type' => 'select',
    '#default_value' => $settings['image_styles']['views_lightslider_image_thumb_style'],
    '#empty_option' => t('None (original image)'),
    '#options' => $image_styles,
    '#description' => t('Content image style.'),
  );

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function views_lightslider_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $summary = array();

  $image_styles = image_style_options(FALSE);
  // Unset possible 'No defined styles' option.
  unset($image_styles['']);
  // Styles could be lost because of enabled/disabled modules that defines
  // their styles in code.
  if (isset($image_styles[$settings['image_styles']['views_lightslider_image_style']])) {
    $summary[] = t('views_lightslider image style: @style',
      array('@style' => $image_styles[$settings['image_styles']['views_lightslider_image_style']]));
  }
  else {
    $summary[] = t('views_lightslider image style: Original image');
  }

  if (isset($image_styles[$settings['image_styles']['views_lightslider_image_thumb_style']])) {
    $summary[] = t('Content image style: @style',
      array('@style' => $image_styles[$settings['image_styles']['views_lightslider_image_thumb_style']]));
  }
  else {
    $summary[] = t('Content image style: Original image');
  }

  $summary[] = ($settings['views_lightslider_thumbs']['thumbnails']) ? t('Use thumbs in gallery: Yes') : t('Use thumbs in gallery: No');

  return implode('<br />', $summary);
}

/**
 * Implements hook_field_formatter_view().
 */
function views_lightslider_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  // Render elements as one piece of markup so that items can be rendered as item list.
  $element[0] = array(
    '#theme' => 'views_lightslider_image_formatter',
    '#items' => $items,
    '#entity_type' => $entity_type,
    '#entity' => $entity,
    '#node' => $entity, // Left for legacy support.
    '#field' => $field,
    '#display_settings' => $display['settings'],
  );

  return $element;
}