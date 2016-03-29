<?php
/**
 * @file
 * Provide the views lightSlider plugin object with default options and form.
 */

/**
 * Implementation of views_plugin_style().
 */
class views_lightslider_style_plugin extends views_plugin_style {
  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();
    unset($options['grouping']);

    $options['style'] = array('default' => 'default');
    $options['item'] = array('default' => '3');
    $options['mode'] = array('default' => 'slide');
    $options['autoWidth'] = array('default' => 'false');
    $options['slideMove'] = array('default' => '1');
    $options['slideMargin'] = array('default' => '10');
    $options['useCSS'] = array('default' => 'true');
    $options['cssEasing'] = array('default' => 'ease');
    $options['easing'] = array('default' => 'linear');
    $options['speed'] = array('default' => '400');
    $options['autoPlay'] = array('default' => 'false');
    $options['pauseOnHover'] = array('default' => 'false');
    $options['loop'] = array('default' => 'true');
    $options['slideEndAnimation'] = array('default' => 'true');
    $options['pause'] = array('default' => '2000');
    $options['keyPress'] = array('default' => 'false');
    $options['controls'] = array('default' => 'true');
    $options['prevHtml'] = array('default' => '');
    $options['nextHtml'] = array('default' => '');
    $options['rtl'] = array('default' => 'false');
    $options['adaptiveHeight'] = array('default' => 'false');
    $options['vertical'] = array('default' => 'false');
    $options['verticalHeight'] = array('default' => '500');
    $options['vThumbWidth'] = array('default' => '100');
    $options['thumbItem'] = array('default' => '10');
    $options['pager'] = array('default' => 'true');
    $options['gallery'] = array('default' => 'true');
    $options['galleryThumbImageStyle'] = array('default' => '');
    $options['galleryMargin'] = array('default' => '5');
    $options['thumbMargin'] = array('default' => '3');
    $options['currentPagerPosition'] = array('default' => 'middle');
    $options['enableTouch'] = array('default' => 'true');
    $options['enableDrag'] = array('default' => 'true');
    $options['freeMove'] = array('default' => 'true');

    $options['responsive'] = array('default' => '_none');
    $options['responsive_1']['breakpoint'] = array('default' => '');
    $options['responsive_1']['item'] = array('default' => '');
    $options['responsive_1']['slideMove'] = array('default' => '');
    $options['responsive_1']['slideMargin'] = array('default' => '');
    $options['responsive_1']['thumbItem'] = array('default' => '');
    $options['responsive_1']['thumbMargin'] = array('default' => '');
    $options['responsive_2']['breakpoint'] = array('default' => '');
    $options['responsive_2']['item'] = array('default' => '');
    $options['responsive_2']['slideMove'] = array('default' => '');
    $options['responsive_2']['slideMargin'] = array('default' => '');
    $options['responsive_2']['thumbItem'] = array('default' => '');
    $options['responsive_2']['thumbMargin'] = array('default' => '');
    $options['responsive_3']['breakpoint'] = array('default' => '');
    $options['responsive_3']['item'] = array('default' => '');
    $options['responsive_3']['slideMove'] = array('default' => '');
    $options['responsive_3']['slideMargin'] = array('default' => '');
    $options['responsive_3']['thumbItem'] = array('default' => '');
    $options['responsive_3']['thumbMargin'] = array('default' => '');

    // @todo - define Callbacks
    // @todo - define Public Functions

    return $options;
  }
  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    unset($form['grouping']);

    $presets = array();
    foreach (image_styles() as $p) {
      $presets[$p['name']] = $p['name'];
    }

    $form['style'] = array(
      '#type' => 'select',
      '#title' => t('Style'),
      '#default_value' => $this->options['style'],
      '#options' => $this->get_style_options(),
    );

    $form['item'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of slides'),
      '#default_value' => $this->options['item'],
      '#description' => t('Number of slides to show at a time - enter integer number'),
      '#size' => '4',
    );

    $form['mode'] = array(
      '#type' => 'select',
      '#title' => t('Mode'),
      '#default_value' => $this->options['mode'],
      '#options' => array('slide' => t('Slide'), 'fade' => t('Fade')),
      '#multiple' => FALSE,
    );

    $form['autoWidth'] = array(
      '#type' => 'select',
      '#title' => t('Custom width for each slide'),
      '#default_value' => $this->options['autoWidth'],
      '#options' => array('true' => t('Yes'), 'false' => t('No')),
    );

    $form['slideMove'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of slides to be moved at a time'),
      '#default_value' => $this->options['slideMove'],
      '#description' => 'Enter integer number',
      '#size' => '4',
    );

    $form['slideMargin'] = array(
    '#type' => 'textfield',
    '#title' => t('Spacing between each slide'),
    '#default_value' => $this->options['slideMargin'],
    '#description' => 'Enter integer number equal to amount of desired margin in px. (e.g., 10)',
    '#size' => '4',
    );

    $form['addClass'] = array(
      '#type' => 'textfield',
      '#title' => t('Custom Class'),
      '#default_value' => $this->options['addClass'],
      '#description' => 'Add custom class for slider. Can be used to set different style for different sliders.',
      '#size' => '30',
    );

    $form['useCSS'] = array(
      '#type' => 'select',
      '#title' => t('Use CSS transitions'),
      '#default_value' => $this->options['useCSS'],
      '#description' => '	If Yes, LightSlider will use CSS transitions. If No, jQuery animation will be used.',
      '#options' => array('true' => t('Yes'), 'false' => t('No')),
    );

    $form['cssEasing'] = array(
      '#type' => 'textfield',
      '#title' => t('CSS Easing'),
      '#default_value' => $this->options['cssEasing'],
      '#description' => 'Type of easing to be used for CSS animations',
      '#size' => '30',
    );

    $form['easing'] = array(
      '#type' => 'textfield',
      '#title' => t('Easing'),
      '#default_value' => $this->options['easing'],
      '#description' => 'Type of easing to be used for jQuery animations',
      '#size' => '30',
    );

    $form['speed'] = array(
      '#type' => 'textfield',
      '#title' => t('Speed'),
      '#default_value' => $this->options['speed'],
      '#description' => 'Transition duration (in ms). // ex = 400',
      '#size' => '6',
    );

    $form['auto'] = array(
      '#type' => 'select',
      '#title' => t('AutoPlay'),
      '#default_value' => $this->options['auto'],
      '#description' => 'If set to Yes, the Slider will automatically start to play.',
      '#options' => array('true' => t('Yes'), 'false' => t('No')),
    );

    $form['pauseOnHover'] = array(
        '#type' => 'select',
        '#title' => t('Pause on Hover'),
        '#default_value' => $this->options['pauseOnHover'],
        '#description' => 'Pause autoplay on hover.',
        '#options' => array('true' => t('Yes'), 'false' => t('No')),
    );

    $form['loop'] = array(
      '#type' => 'select',
      '#title' => t('Loop'),
      '#default_value' => $this->options['loop'],
      '#description' => 'If No, will disable the ability to loop back to the beginning of the slider when on the last element.',
      '#options' => array('true' => t('Yes'), 'false' => t('No')),
    );

    $form['slideEndAnimation'] = array(
      '#type' => 'select',
      '#title' => t('Enable slideEnd animation'),
      '#default_value' => $this->options['slideEndAnimation'],
      '#options' => array('true' => t('Yes'), 'false' => t('No')),
    );

    $form['pause'] = array(
      '#type' => 'textfield',
      '#title' => t('Pause'),
      '#default_value' => $this->options['pause'],
      '#description' => 'The time (in ms) between each auto transition',
      '#size' => '6',
    );

    $form['keyPress'] = array(
      '#type' => 'select',
      '#title' => t('Enable keyboard navigation'),
      '#default_value' => $this->options['keyPress'],
      '#options' => array('true' => t('Yes'), 'false' => t('No')),
    );

    $form['controls'] = array(
      '#type' => 'select',
      '#title' => t('Enable Controls'),
      '#default_value' => $this->options['controls'],
      '#options' => array('true' => t('Yes'), 'false' => t('No')),
      '#description' => t('If No, prev/next buttons will not be displayed.'),
    );

    $form['prevHtml'] = array(
      '#type' => 'textfield',
      '#title' => t('Custom HTML for prev control'),
      '#default_value' => $this->options['prevHtml'],
      '#size' => '30',
    );

    $form['nextHtml'] = array(
      '#type' => 'textfield',
      '#title' => t('Custom HTML for next control'),
      '#default_value' => $this->options['nextHtml'],
      '#size' => '30',
    );

    $form['rtl'] = array(
      '#type' => 'select',
      '#title' => t('Right-to-Left.'),
      '#default_value' => $this->options['rtl'],
      '#options' => array('true' => t('Yes'), 'false' => t('No')),
      '#description' => t('Change direction to right-to-left.'),
    );

    $form['adaptiveHeight'] = array(
      '#type' => 'select',
      '#title' => t('Adaptive Height'),
      '#default_value' => $this->options['adaptiveHeight'],
      '#options' => array('true' => t('Yes'), 'false' => t('No')),
      '#description' => 'Dynamically adjust slider height based on each slide\'s height',
    );

    $form['vertical'] = array(
      '#type' => 'select',
      '#title' => t('Vertical slide\'s direction'),
      '#default_value' => $this->options['vertical'],
      '#options' => array('true' => t('Yes'), 'false' => t('No')),
    );

    $form['verticalHeight'] = array(
      '#type' => 'textfield',
      '#title' => t('Vertical Height'),
      '#default_value' => $this->options['verticalHeight'],
      '#description' => 'set height of slider if vertical mode is active and item more than 1',
      '#size' => '6',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[vertical]"]' => array('value' => 'true'),
        ),
      ),
    );

    $form['pager'] = array(
      '#type' => 'select',
      '#title' => t('Pager'),
      '#default_value' => $this->options['pager'],
      '#options' => array('true' => t('Yes'), 'false' => t('No')),
      '#description' => 'Enable pager option',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[gallery]"]' => array('value' => 'true'),
        ),
      ),
    );

    $form['gallery'] = array(
      '#type' => 'select',
      '#title' => t('Thumbnail Gallery'),
      '#default_value' => $this->options['gallery'],
      '#options' => array('true' => t('Yes'), 'false' => t('No')),
      '#description' => 'Enable thumbnails gallery',
    );

    $form['galleryThumbImageStyle'] = array(
      '#type' => 'select',
      '#title' => t('Image style for use in thumbs'),
      '#default_value' => isset($this->options['galleryThumbImageStyle']) ? $this->options['galleryThumbImageStyle'] : NULL,
      '#options' => array_merge(array('' => t('<none>')), $presets),
      '#states' => array(
          'visible' => array(
          ':input[name="style_options[gallery]"]' => array('value' => 'true'),
        ),
      ),
    );

    $form['vThumbWidth'] = array(
      '#type' => 'textfield',
      '#title' => t('Thumbnail Width'),
      '#default_value' => $this->options['vThumbWidth'],
      '#description' => 'width of gallery thumbnail while vertical mode active',
      '#size' => '6',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[gallery]"]' => array('value' => 'true'),
        ),
      ),
    );

    $form['thumbItem'] = array(
      '#type' => 'textfield',
      '#title' => t('Thumbnail Items'),
      '#default_value' => $this->options['thumbItem'],
      '#description' => 'number of gallery thumbnail to show at a time',
      '#size' => '6',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[gallery]"]' => array('value' => 'true'),
        ),
      ),
    );

    $form['galleryMargin'] = array(
      '#type' => 'textfield',
      '#title' => t('Spacing between thumbnail gallery and slider (in px)'),
      '#default_value' => $this->options['galleryMargin'],
      '#size' => '6',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[gallery]"]' => array('value' => 'true'),
        ),
      ),
    );

    $form['thumbMargin'] = array(
      '#type' => 'textfield',
      '#title' => t('Spacing between each thumbnail (in px)'),
      '#default_value' => $this->options['thumbMargin'],
      '#size' => '6',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[gallery]"]' => array('value' => 'true'),
        ),
      ),
    );

    $form['currentPagerPosition'] = array(
      '#type' => 'select',
      '#title' => t('Position of thumbnails . \'left\', \'middle\', \'right\''),
      '#default_value' => $this->options['currentPagerPosition'],
      '#options' => array('left' => t('Left'), 'middle' => t('Middle'), 'right' => 'Right'),
    );

    $form['enableTouch'] = array(
      '#type' => 'select',
      '#title' => t('Enable touch support'),
      '#default_value' => $this->options['enableTouch'],
      '#options' => array('true' => t('Yes'), 'false' => t('No')),
    );

    $form['enableDrag'] = array(
      '#type' => 'select',
      '#title' => t('Enable desktop mouse drag support'),
      '#default_value' => $this->options['enableDrag'],
      '#options' => array('true' => t('Yes'), 'false' => t('No')),
    );

    $form['freeMove'] = array(
      '#type' => 'select',
      '#title' => t('Enable free move(no limit) while swipe or drag'),
      '#default_value' => $this->options['freeMove'],
      '#options' => array('true' => t('Yes'), 'false' => t('No')),
    );

    $form['responsive'] = array(
      '#type' => 'select',
      '#title' => t('Responsive breakpoints'),
      '#default_value' => $this->options['responsive'],
      '#options' => array_merge(array('' => t('_none')), drupal_map_assoc(range(1, 3))),
      '#description' => t('Scroll down and define settings for each breakpoint'),
    );

    // breakpoints support options: item, slideMove, slideMargin, thumbItem, thumbMargin
    // so we need to provide fieldset which will allow to set those options
    // for each breakpoint
    // Let's start with 3 breakpoints
    $form['responsive_1'] = array(
      '#title' => 'Breakpoint #1 Settings',
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => '0'), array('value' => 1), array('value' => 2)),
        ),
      ),
    );
    $form['responsive_1']['breakpoint'] = array(
      '#type' => 'textfield',
      '#title' => t('Breakpoint #1 in px'),
      '#default_value' => $this->options['responsive_1']['breakpoint'],
      '#description' => t('e.g., 800'),
      '#size' => '4',
      '#required' => TRUE,
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => '0'), array('value' => 1), array('value' => 2)),
        ),
      ),
    );
    $form['responsive_1']['item'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of slides'),
      '#default_value' => $this->options['responsive_1']['item'],
      '#description' => t('Number of slides to show at a time - enter integer number'),
      '#size' => '4',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => '0'), array('value' => 1), array('value' => 2)),
        ),
      ),
    );

    $form['responsive_1']['slideMove'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of slides to be moved at a time'),
      '#default_value' => $this->options['responsive_1']['slideMove'],
      '#description' => 'Enter integer number',
      '#size' => '4',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => '0'), array('value' => 1), array('value' => 2)),
        ),
      ),
    );

    $form['responsive_1']['slideMargin'] = array(
      '#type' => 'textfield',
      '#title' => t('Spacing between each slide'),
      '#default_value' => $this->options['responsive_1']['slideMargin'],
      '#description' => 'Enter integer number equal to amount of desired margin in px. (e.g., 10)',
      '#size' => '4',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => '0'), array('value' => 1), array('value' => 2)),
        ),
      ),
    );

    $form['responsive_1']['thumbItem'] = array(
      '#type' => 'textfield',
      '#title' => t('Thumbnail Items'),
      '#default_value' => $this->options['responsive_1']['thumbItem'],
      '#description' => 'number of gallery thumbnail to show at a time',
      '#size' => '6',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => '0'), array('value' => 1), array('value' => 2)),
        ),
      ),
    );

    $form['responsive_1']['thumbMargin'] = array(
      '#type' => 'textfield',
      '#title' => t('Spacing between each thumbnail (in px)'),
      '#default_value' => $this->options['responsive_1']['thumbMargin'],
      '#size' => '6',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => '0'), array('value' => 1), array('value' => 2)),
        ),
      ),
    );

    // Breakpoint #2 settings form
    $form['responsive_2'] = array(
      '#title' => 'Breakpoint #2 Settings',
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => 1), array('value' => 2)),
        ),
      ),
    );
    $form['responsive_2']['breakpoint'] = array(
      '#type' => 'textfield',
      '#title' => t('Breakpoint #2 in px'),
      '#default_value' => $this->options['responsive_2']['breakpoint'],
      '#description' => t('e.g., 800'),
      '#size' => '4',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => 1), array('value' => 2)),
        ),
      ),
    );
    $form['responsive_2']['item'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of slides'),
      '#default_value' => $this->options['responsive_2']['item'],
      '#description' => t('Number of slides to show at a time - enter integer number'),
      '#size' => '4',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => 1), array('value' => 2)),
        ),
      ),
    );

    $form['responsive_2']['slideMove'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of slides to be moved at a time'),
      '#default_value' => $this->options['responsive_2']['slideMove'],
      '#description' => 'Enter integer number',
      '#size' => '4',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => 1), array('value' => 2)),
        ),
      ),
    );

    $form['responsive_2']['slideMargin'] = array(
      '#type' => 'textfield',
      '#title' => t('Spacing between each slide'),
      '#default_value' => $this->options['responsive_2']['slideMargin'],
      '#description' => 'Enter integer number equal to amount of desired margin in px. (e.g., 10)',
      '#size' => '4',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => 1), array('value' => 2)),
        ),
      ),
    );

    $form['responsive_2']['thumbItem'] = array(
      '#type' => 'textfield',
      '#title' => t('Thumbnail Items'),
      '#default_value' => $this->options['responsive_2']['thumbItem'],
      '#description' => 'number of gallery thumbnail to show at a time',
      '#size' => '6',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => 1), array('value' => 2)),
        ),
      ),
    );

    $form['responsive_2']['thumbMargin'] = array(
      '#type' => 'textfield',
      '#title' => t('Spacing between each thumbnail (in px)'),
      '#default_value' => $this->options['responsive_2']['thumbMargin'],
      '#size' => '6',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => 1), array('value' => 2)),
        ),
      ),
    );
    // Breakpoint #3 settings form
    $form['responsive_3'] = array(
      '#title' => 'Breakpoint #3 Settings',
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => 2)),
        ),
      ),
    );
    $form['responsive_3']['breakpoint'] = array(
      '#type' => 'textfield',
      '#title' => t('Breakpoint #3 in px'),
      '#default_value' => $this->options['responsive_3']['breakpoint'],
      '#description' => t('e.g., 800'),
      '#size' => '4',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => 2)),
        ),
      ),
    );
    $form['responsive_3']['item'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of slides'),
      '#default_value' => $this->options['responsive_3']['item'],
      '#description' => t('Number of slides to show at a time - enter integer number'),
      '#size' => '4',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => 2)),
        ),
      ),
    );

    $form['responsive_3']['slideMove'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of slides to be moved at a time'),
      '#default_value' => $this->options['responsive_3']['slideMove'],
      '#description' => 'Enter integer number',
      '#size' => '4',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => 2)),
        ),
      ),
    );

    $form['responsive_3']['slideMargin'] = array(
      '#type' => 'textfield',
      '#title' => t('Spacing between each slide'),
      '#default_value' => $this->options['responsive_3']['slideMargin'],
      '#description' => 'Enter integer number equal to amount of desired margin in px. (e.g., 10)',
      '#size' => '4',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => 2)),
        ),
      ),
    );

    $form['responsive_3']['thumbItem'] = array(
      '#type' => 'textfield',
      '#title' => t('Thumbnail Items'),
      '#default_value' => $this->options['responsive_3']['thumbItem'],
      '#description' => 'number of gallery thumbnail to show at a time',
      '#size' => '6',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => 2)),
        ),
      ),
    );

    $form['responsive_3']['thumbMargin'] = array(
      '#type' => 'textfield',
      '#title' => t('Spacing between each thumbnail (in px)'),
      '#default_value' => $this->options['responsive_3']['thumbMargin'],
      '#size' => '6',
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[responsive]"]' => array(array('value' => 2)),
        ),
      ),
    );
  }
  /**
   * {@inheritdoc}
   */
  function validate() {
    parent::validate();
    $errors = array();
    // Output the error message if pager is enabled
    if ($this->display->handler->use_pager()) {
      $errors[] = t('The lightSlider plugin cannot be used with a pager. Please disable the "Use pager" option for this display.');
      //$this->display->options['use_pager'] = FALSE;
    }
    if ($this->display->handler->use_more()) {
      $errors[] = t('The lightSlider plugin cannot be used with "more link". Please disable the "More link" option for this display.');
    }

    return $errors;
  }
  /**
   * {@inheritdoc}
   */
  public function get_style_options() {
    // get list of available themes
    return views_lightslider_list_themes();
  }

}