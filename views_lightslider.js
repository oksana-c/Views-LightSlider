/**
 * @file
 * JS to init lightSlider.
 */
(function ($) {
  Drupal.behaviors.viewsLightSliderBehavior = {
    attach: function (context) {
      $('.views-lightslider', context).once('lightslider', function () {
        var vls = $(this);
        var id = vls.attr('id');
        var config = Drupal.settings.views_lightslider[id];

        // Place Controls outside of lSSlideouter
        if (config['controls'] && config['prevHtml'] && config['nextHtml']) {
          vls.after('<div class="lSAction"><a class="lSPrev">' + config.prevHtml + '</a><a class="lSNext">' + config.nextHtml + '</a></div>');
          // activate left control
          var prev = vls.parent().find('.lSPrev');
          prev.on('click', function () {
            vls.goToPrevSlide(); 
          });

          // active right control
          var next = vls.parent().find('.lSNext');
          next.on('click', function () {
            vls.goToNextSlide();
          });
        }

        vls.lightSlider(config);

        if (config['controls'] && config['prevHtml'] && config['nextHtml']) {
          vls.parent().find('.lSAction').remove();
        }
      });
    }
  };

})(jQuery);