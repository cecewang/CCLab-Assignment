//taskArray
var taskArray = [];


//deletetask
var deleteTask = function(e){

	var taskNumber = e.target.parentElement.id; 	
  	taskArray.splice(taskNumber, 1);
  	updateTasks();
	
};

//saveTask
var saveTask = function(){
	//define the task input form and value
	//不要忘记#！！！
	//val() 无参数时，该函数的作用是返回value的值；
	//有参数时，作用是把value设置为你传进去的参数
	var newTask = $('#newTask').val();

	//add the value to the task array
	taskArray.push(newTask);

	//clear the input, 输入完之后输入框要被清空
	$('#newTask').val('');

	//fire up the updateTasks
	updateTasks();

	//log the task array to make sure all the things work
	console.log(taskArray);
};


//updateTasks
var updateTasks = function(){
	//empty(): 清空taskList里的所有节点DOM
	//#又忘记！！！！！！！！！
	$('#taskList').empty();
	//each(): 对所有符合要求的jQuery对象，重复做这个函数的要求
	//i指的是taskArray的index, this对应i索引的元素
	$(taskArray).each(function(i){
		console.log("task" + i + ':'+ this);

		//创造新元素button
		var deleteButton = $('<button/>');
		//attr()得到匹配set的第一个元素的属性值 或 为每个匹配值设定一或多个属性值
		//设置多个东西可以连在一起写
		//text就是添了个字<deleteButton id = "deleteButton">DELETE</deleteButotn>
		deleteButton.attr('id', 'deleteButton').text('X').click(function(e){
			deleteTask(e);
		});

		var newTask = $('<div/>');
		//添加一个类，在里面添加一个html元素<p>
		//text里面的东西不会作为html标签解释，但html可以解析标签，所以它还可以用来添加节点
		newTask.attr('id', i).addClass('task').html('<p>' + this + '</p>');
		//newTask是父元素, 而且不是appendChild!!!!
		newTask.append(deleteButton);

		//#又忘记加了！！
		$('#taskList').append(newTask);

		$('.task').hover(function(){	
			$(this).css("background","#5656C0");
		});
		$('.task p').hover(function(){	
			$(this).css("background","#5656C0");
		});
		
		$('.task').mouseout(function(){	
			$(this).css("background","white");
		});
		$('.task p').mouseout(function(){	
			$(this).css("background","white");
		});
		$('#deleteButton').click(function(){
			// var a = 
			// var color = '#"'a'""'b'""'c'"';

			$('#myAwesomeToDoList').css("background","#D15E81");
		});


	});	
};



//init
var init = function(){
	//确保jquery被正确加载并运行成功
	console.log("hey jquery!");

	// do the same things as the former function does using jquery
	// define the button and wait for the click event
	// #代表ID
	$('#addButton').click(function(e){
		e.preventDefault();
		saveTask();
	});

};

//load listener
//jquery的syntax是长成这样的, 
//selector表示任何可选的html相关元素, 
//action那里就是你的function
//$("selector").action()

//一旦加载index页面的时候, js就开始初始化并运行
//$() - turns whatever is inside () into an object
$(document).ready(init);




