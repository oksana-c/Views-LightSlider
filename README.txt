Views LightSlider is used to create lightweight, responsive content sliders that feature optional carousel thumbnails or pager navigation.
It is powered by jQuery plugin lightSlider [http://sachinchoolur.github.io/lightslider/index.html].
This module is a Views style plugin that allows for each slider to be individually customized with multiple settings. Module includes two custom slider skins(themes).

----------------------------
-- DEPENDENCIES
----------------------------
[Libraries API module](http://drupal.org/project/libraries)
[Views module](http://drupal.org/project/views)
[jQuery Update module](http://drupal.org/project/jquery_update) (jQuery v. 1.7 or higher)

----------------------------
-- INSTALLATION
----------------------------
1. If not already installed, download and install the dependencies above. 
2. Install the jQuery Update module and use at least jQuery 1.7 or upgrade the default version of jQuery in your Drupal installation in some other way. Slider preview is immediately displayed in the preview section as you are building your View. Make sure your admin theme uses jQuery v. 1.7 or higher in order to avoid bugs in slider preview.
3. Download the lightSlider plugin - http://sachinchoolur.github.io/lightslider
and place the resulting directory into the sites/all/libraries directory.
Make sure the following files are available:
- sites/all/libraries/lightslider/dist/js/lightslider.min.js
- sites/all/libraries/lightslider/dist/js/lightslider.js
- sites/all/libraries/lightslider/dist/css/lightslider.css
- sites/all/libraries/lightslider/dist/img/controls.png
4. Download the lightSlider module and follow the instructions for [installing
contributed modules](http://drupal.org/node/895232).

----------------------------
-- USAGE
----------------------------
1. Create/Edit a View and add the fields that you would like to use in the content slider.
2. Select the *Views LightSlider* as a View format.
3. Click on the *Settings* link, under the **Format** section.
4. Select/fill out/customize settings for the slider and click apply to apply them to your display.
5. Select *Views LightSlider* as a Row Style (*Show* section).
6. Click on the *Settings* link, under the *Show* section and assign the fields that will be used as the slide's Image, Title, Description and Link from the drop-down select lists. You can assign content to one or all fields.
NOTE: you can combine the content of multiple fields into one  field by adding tokens of those fields to Global:Text field and then displaying the resulting Global:Text field as Title or Description in Row Style settings.
THEMING
Most likely you will require custom CSS styles to be applied to your sliders. In this case, select "Default" skin for the slider and add your custom styles to your current Drupal theme's files.
If you wish to display Prev/Next controls outside of slider container - enter custom HTML for Prev/Next buttons in slider settings.

----------------------------
-- KNOWN ISSUES AND BUGS
----------------------------
Some of the bugs that the jQuery lightSlider plugin has have been resolved, but they may not have been committed to the distributive.
I'll list the most common ones here for reference.
If issues below have a resolution - links will be provided.
You can help fix those issues at [https://github.com/sachinchoolur/lightslider].
 - Equal Height of slides: Content Slider should use "Largest Li Height" for others instead of using the first one [https://github.com/sachinchoolur/lightslider/issues/223]
 - When Loop setting is set to FALSE - pager/thumbnails count equals the number of items shown on load.
 - Setting slideMargin in responsive breakpoint settings makes the slide layout malfunction when the breakpoint is in effect.

----------------------------
-- IDEAS FOR CONTRIBUTIONS
----------------------------
Patches & improvements welcome. 
Features that will be implemented in the near feature are:
- Support for jQuery public methods
- Support for jQuery callbacks
- Integration of lightGallery (http://sachinchoolur.github.io/lightGallery/)