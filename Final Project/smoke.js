(function () {
    var requestAnimationFrame = window.requestAnimationFrame || window.mozRequestAnimationFrame || window.webkitRequestAnimationFrame || window.msRequestAnimationFrame;
    window.requestAnimationFrame = requestAnimationFrame;
})();

var canvas = document.getElementById("canvas"),
    ctx = canvas.getContext("2d");

canvas.height = 300;
// canvas.width = document.body.offsetWidth;
canvas.width = 1154;

var parts = [],
    minSpawnTime = 40,
    lastTime = new Date().getTime(),
    // maxLifeTime = Math.min(5000, (canvas.height/(1.5*60)*1000)),
    maxLifeTime = 20000,
    emitterX = canvas.width / 2,
    emitterY = 0,
    smokeImage1 = new Image(),
    smokeImage2 = new Image(),
    smokeImage3 = new Image(),
    smokeImage4 = new Image(),
    smokeImage5 = new Image(),
    smokeImage6 = new Image(),
    smokeImage7 = new Image(),
    smokeImage8 = new Image(),
    smokeImage9 = new Image(),
    smokeImage10 = new Image(),
    smokeImage11 = new Image(),
    smokeImage12 = new Image(),
    steps = [],
    end = false;

function spawn() {
    if(!end){
        if (new Date().getTime() > lastTime + minSpawnTime) {
            lastTime = new Date().getTime();
            for (var i = 0; i < steps.length; i++){
                var t = (canvas.width-60)/13;
                var tempx = steps[i]*(t+15)-20;
                var tempy = 50;
                var image;
                // console.log(steps[i]);
                switch(steps[i]){
                    case 1:
                    image = smokeImage1;
                    break;
                    case 2:
                    image = smokeImage2; 
                    break;
                    case 3:
                    image = smokeImage3;
                    break;
                    case 4:
                    image = smokeImage4;
                    break;
                    case 5:
                    image = smokeImage5;
                    break;
                    case 6:
                    image = smokeImage6;
                    break;
                    case 7:
                    image = smokeImage7;
                    break;
                    case 8:
                    image = smokeImage8;
                    break;
                    case 9:
                    image = smokeImage9;
                    break;
                    case 10:
                    image = smokeImage10;
                    break;
                    case 11:
                    image = smokeImage11;
                    break;
                    case 12:
                    image = smokeImage12;
                    break;
                    case 13:
                    image = smokeImage1;
                    break;
                    case 14:
                    image = smokeImage2; 
                    break;
                    case 15:
                    image = smokeImage3;
                    break;
                    case 16:
                    image = smokeImage4;
                    break;
                    case 17:
                    image = smokeImage5;
                    break;
                    case 18:
                    image = smokeImage6;
                    break;
                    case 19:
                    image = smokeImage7;
                    break;
                    case 20:
                    image = smokeImage8;
                    break;
                    case 21:
                    image = smokeImage9;
                    break;
                    case 22:
                    image = smokeImage10;
                    break;
                    case 23:
                    image = smokeImage11;
                    break;
                    case 24:
                    image = smokeImage12;
                    break;
                    case 25:
                    image = smokeImage11;
                    break;
                    case 26:
                    image = smokeImage12;
                    break;
                    default:
                    break;
                }
                parts.push(new smoke(tempx, tempy, image));
            }
        }
    }else{
        if (new Date().getTime() > lastTime + minSpawnTime) {
            lastTime = new Date().getTime();
            var smoke1 = new smoke(0, 300, smokeImage9);
            var tmp = 0;
            tmp = smoke1.velX;
            smoke1.velX = smoke1.velY;
            smoke1.velY = tmp;
            parts.push(smoke1);
            var smoke2 = new smoke(canvas.width, 300, smokeImage9);
            tmp = -smoke2.velX;
            smoke2.velX = -smoke2.velY;
            smoke2.velY = tmp;
            parts.push(smoke2);
        }
    }
}
function resetAll(){
    steps = [];
    // maxLifeTime *=2;
}
function render() {
    var len = parts.length;
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    while (len--) {
        if (parts[len].y < 0 || parts[len].lifeTime > maxLifeTime) {
            parts.splice(len, 1);
        } else {
            parts[len].update();

            ctx.save();
            var offsetX = -parts[len].size/2,
                offsetY = -parts[len].size/2;
         
            ctx.translate(parts[len].x-offsetX, parts[len].y-offsetY);
            ctx.rotate(parts[len].angle / 180 * Math.PI);
            ctx.globalAlpha  = parts[len].alpha;
            ctx.drawImage(parts[len].image, offsetX,offsetY, parts[len].size, parts[len].size);
            ctx.restore();
        }
    }
    spawn();
    requestAnimationFrame(render);
}

function smoke(x, y, image) {
    this.x = x;
    this.y = y;
    this.image = image;

    this.size = 1;
    this.startSize = 32;
    this.endSize = 40;

    this.angle = Math.random() * 359;

    this.startLife = new Date().getTime();
    this.lifeTime = 0;

    this.velY = -1 - (Math.random()*0.5);
    this.velX = Math.floor(Math.random() * (-6) + 3) / 10;
}

smoke.prototype.update = function () {
    this.lifeTime = new Date().getTime() - this.startLife;
    this.angle += 0.2;
    
    var lifePerc = ((this.lifeTime / maxLifeTime) * 300);

    this.size = this.startSize + ((this.endSize - this.startSize) * lifePerc * .1);

    this.alpha = 1 - (lifePerc * .01);
    this.alpha = Math.max(this.alpha,0);
    
    this.x -= this.velX;
    this.y -= this.velY;
}

smokeImage1.src = "smokepink.png";
smokeImage2.src = "smokeyellow.png";
smokeImage3.src = "smokegreen.png";
smokeImage4.src = "smokeblue.png";
smokeImage5.src = "smokepurple.png";
smokeImage6.src = "smokepurpin.png";
smokeImage7.src = "smokeblue.png";
smokeImage8.src = "smokeyellow.png";
smokeImage9.src = "smokegrey.png";
smokeImage10.src = "smokegreen.png";
smokeImage11.src = "smokepink.png";
smokeImage12.src = "smokepurple.png";
smokeImage1.onload = function () {
    render();
}


window.onresize = resizeMe;
window.onload = resizeMe;
function resizeMe() {
   canvas.height = document.body.offsetHeight;
}