#include "ofApp.h"
#include <List>
#include <Vector>

//direction----->Up:0 Down:1 Left:3 Right:4
int direction = -1;

list<vector<int> > body;
list<vector<int> > stone;
list<vector<int> >::iterator bodyIterator;
int haveSthToEat = -1;//-1:nothing to eat 0:fat 1:thin
int FoodX = -1;
int FoodY = -1;
int opacity = 150;
bool died = false;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(40, 40, 40);
    for (int i =0; i<25; i++) {
        vector<int> v(2);
        v[0] = i;
        v[1] = 0;
        body.push_back(v);
    }
    cout<<(-1)%30;
}

//--------------------------------------------------------------
void ofApp::update(){
    if(direction == -1)
        return;
    bodyIterator = body.end();
    bodyIterator--;
    vector<int> v1 = *bodyIterator;
    int tmpX = v1[0];
    int tmpY = v1[1];
    vector<int> v2(2);
    switch (direction) {
        case 0://Up
            tmpX = tmpX;
            tmpY = tmpY-1;
            break;
        case 1://Down
            tmpX = tmpX;
            tmpY = tmpY+1;
            break;
        case 2://Left
            tmpX = tmpX-1;
            tmpY = tmpY;
            break;
        case 3://Right
            tmpX = tmpX+1;
            tmpY = tmpY;
            break;
        default:
            break;
    }
    if(tmpX>30)
        tmpX = tmpX-30;
    if(tmpY>30)
        tmpY = tmpY-30;
    if(tmpX<0)
        tmpX = tmpX+30;
    if(tmpY<0)
        tmpY = tmpY+30;
    v2[0] = tmpX;
    v2[1] = tmpY;
    ifDie(tmpX, tmpY);
    if(tmpX == FoodX && tmpY == FoodY){
        if(haveSthToEat == 1){
            body.pop_front();
            body.pop_front();
        }
        haveSthToEat = -1;
    }else{
        body.pop_front();
    }
    body.push_back(v2);
}
bool ofApp::ifDie(int x, int y){
    for(bodyIterator = body.begin();bodyIterator!=body.end();++bodyIterator){
        vector<int> v = *bodyIterator;
        if(v[0] == x && v[1] == y){
            died = true;
            return true;
        }
    }
    for(bodyIterator = stone.begin();bodyIterator!=stone.end();++bodyIterator){
        vector<int> v = *bodyIterator;
        if(v[0] == x && v[1] == y){
            died = true;
            return true;
        }
    }
    return false;
}

//--------------------------------------------------------------
void ofApp::draw(){
    //    int startX = 10;
    //    int startY = 30;
    //    int vel = ofGetElapsedTimef()*5;
    //
    if(died){
        ofSetColor(255,255,255,255);
        ofDrawBitmapString("You Died!", 250, 250);
        return;
    }
    if (opacity>=300) {
        opacity=0;
    }
    opacity+=20;
    int transparent = opacity<150 ? opacity : 300-opacity;
    if(haveSthToEat == -1){
        FoodX = (int)ofRandom(0, 30);
        FoodY = (int)ofRandom(0, 30);
        haveSthToEat = ofRandom(0,1)>0.8 ? 1:0;
        if(body.size()<=3)
            haveSthToEat = 0;
    }
    switch (haveSthToEat) {
        case 0:
            ofSetColor(255, 0, 0, transparent);
            break;
        case 1:
            ofSetColor(0, 255, 0, transparent);
            break;
        default:
            break;
    }
    if(ofRandom(0,1)>0.98){
        vector<int> stoneV(2);
        stoneV[0] = (int)ofRandom(0, 30);
        stoneV[1] = (int)ofRandom(0, 30);
        stone.push_back(stoneV);
    }
    ofRect(FoodX*20+1, FoodY*20+1, 19, 19);
    ofSetColor(255, 255, 255, transparent);
    for(bodyIterator = body.begin();bodyIterator!=body.end();++bodyIterator){
        vector<int> v = *bodyIterator;
        int tempX = v[0]*20+1;
        int tempY = v[1]*20+1;
        ofRect(tempX, tempY, 19, 19);
    }
    ofSetColor(0, 0, 255, transparent);
    for(bodyIterator = stone.begin();bodyIterator!=stone.end();++bodyIterator){
        vector<int> v = *bodyIterator;
        int tempX = v[0]*20+1;
        int tempY = v[1]*20+1;
        ofRect(tempX, tempY, 19, 19);
    }
    
    //    ofRect(quaX*16 + vel*16, quaY*16, 14, 14);
    //    ofRect((quaX+1+vel)*16, quaY*16, 14, 14);
    //    ofRect((quaX+2+vel)*16, quaY*16, 14, 14);
    //    ofRect((quaX+3+vel)*16, quaY*16, 14, 14);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'w'){
        direction = 0;
    }else if(key == 's'){
        direction = 1;
    }else if(key == 'a'){
        direction = 2;
    }else if(key == 'd'){
        direction = 3;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
