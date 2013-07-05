$ = jQuery;

$('document').ready(function(){
  $('#header #site-name a').click(function(event) {
    event.preventDefault();
    $('#header').toggleClass('open');
  })
});