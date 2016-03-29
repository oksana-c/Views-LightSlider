<?php
/**
 * @file
 * Contains the base row style plugin.
 */
/**
 * The basic 'fields' row plugin
 *
 * This displays fields one after another.
 *
 * @ingroup views_row_plugins
 */
class views_lightslider_plugin_row_lightsliderfields extends views_plugin_row {
  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['image_field'] = array('default' => '');
    $options['title_field'] = array('default' => '');
    $options['description_field'] = array('default' => '');
    $options['link_field'] = array('default' => '');
    return $options;
  }
  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Pre-build all of our option lists for the dials and switches that follow.
    $fields = array('' => t('<none>'));
    foreach ($this->display->handler->get_handlers('field') as $field => $handler) {
      if ($label = $handler->label()) {
        $fields[$field] = $label;
      }
      else {
        $fields[$field] = $handler->ui_name();
      }
    }

    $form['image_field'] = array(
      '#type' => 'select',
      '#title' => t('Image field'),
      '#options' => $fields,
      '#default_value' => $this->options['image_field'],
      '#description' => t('Select the field that will be used as the image field.'),
    );

    $form['title_field'] = array(
      '#type' => 'select',
      '#title' => t('Title field'),
      '#options' => $fields,
      '#default_value' => $this->options['title_field'],
      '#description' => t('Select the field that will be used as the title field, if one is required.'),
    );

    $form['description_field'] = array(
      '#type' => 'select',
      '#title' => t('Description field'),
      '#options' => $fields,
      '#default_value' => $this->options['description_field'],
      '#description' => t('Select the field that will be used as the description field, if one is required. You can use Views Global Text field to add extra markup or combine multiple fields in one.'),
    );

    $form['link_field'] = array(
      '#type' => 'select',
      '#title' => t('Link field'),
      '#options' => $fields,
      '#default_value' => $this->options['link_field'],
      '#description' => t('Select the field that will be used as the link field, if one is required.'),
    );
  }
}