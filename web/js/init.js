(function($){

  $(function(){
  	$('.button-collapse').sideNav();
    $('.parallax').parallax();
    $('.top_parallax').height(window.innerHeight + 'px');
  	});

	$(window).scroll(function(){
    $(".header").css("opacity", 1 - $(window).scrollTop() / 250);
  	});

	$("#reset-login").on("click", function() {
  	$('label').removeClass('active');
	});

	$("#reset-join").on("click", function() {
  	$('label').removeClass('active');
	});

})(jQuery);

$(document).ready(function(){
    $('.modal').modal({
		dismissible: true,
		opacity: .5,
		inDuration: 300,
		outDuration: 200,
		ready: function(modal, trigger) { 
        console.log(modal, trigger);
    	}
	});
  });