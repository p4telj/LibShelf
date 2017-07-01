(function($){
  $(function(){

  	$('.button-collapse').sideNav();
    $('.parallax').parallax();
    $('.top_parallax').height(window.innerHeight + 'px');
    


  });


	$(window).scroll(function(){
    $(".header").css("opacity", 1 - $(window).scrollTop() / 250);
  });

})(jQuery);