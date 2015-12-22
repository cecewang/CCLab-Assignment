
$(document).ready(function() {

    $("#next").click(function() {
        $("html,body").animate({
            scrollTop: $("#questionArea").offset().top
        }, 1000);
    });
    $("#q").click(function(){
        $("#q").css("background-image","url('6.png')");
    });
    $("#at1").click(function() {
        if ($("#at1 span").text() == "The End") {
        	end = true;
            resetAll();
        } else {
            var index = currentQuestion.questionIdforA;
            steps.push(step);
            step++;
            currentQuestion = questions[index];
            loadQuestion();
        }
    });
    $("#at2").click(function() {
        var index = currentQuestion.questionIdforB;
        steps.push(step);
        step++;
        currentQuestion = questions[index];
        loadQuestion();

        var audio = document.getElementById('no');
        audio.play();


    });
    var step = 1;
    var questions;
    var currentQuestion;
    $.getJSON('questionnew.json', function(data) {
        questions = data;
        currentQuestion = questions[0];
        loadQuestion();
        hoverAnswer();
        // var audio = $("#no")[0];
    });

    
    function getCurrentTime(id){            
        alert(parseInt(audio.currentTime) + '：秒');
    }

    function playOrPaused(id,obj){
        if(audio.paused){
            audio.play();
            obj.innerHTML='暂停';
            return;
    }
        audio.pause();
        obj.innerHTML='播放';
    }


    function loadQuestion() {
        $("#questionArea").animate({
            'margin-top': '30px',
            'opacity': '0'
        }, 300, function() {
            $("#question").text(currentQuestion.question);
            if(currentQuestion.dataimage){
                $("#dataimage")[0].src = currentQuestion.dataimage;
                console.log(currentQuestion.dataimage);
            }
            
            $("#at1 span").text(currentQuestion.optionA);
            $("#at2 span").text(currentQuestion.optionB);
            $("#questionArea").animate({
                'margin-top': '0',
                'opacity': '1'
            }, 300);
        });
    }

    function hoverAnswer() {
        $("#at1 span").mouseover(function() {
            $("#atl1").animate({
                'width': '50%'
            }, 400);
        });
        $("#at1 span").mouseleave(function() {
            $("#atl1").animate({
                'width': '0'
            }, 400);
        });
        $("#at2 span").mouseover(function() {
            $("#atl2").animate({
                'width': '50%'
            }, 400);
        });
        $("#at2 span").mouseleave(function() {
            $("#atl2").animate({
                'width': '0'
            }, 400);
        });
    }
});