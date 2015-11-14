#include "ofApp.h"

//ofApp::ofApp(){
//    circle1(ofGetWidth()/6, ofGetHeight()/5, 0);
//}
//--------------------------------------------------------------
void ofApp::setup(){
    circle1.setup();
    circle2.setup();
    circle3.setup();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundHex(0Xffffff);
    ofLine(ofGetWidth()/6, ofGetHeight()/5, 5*ofGetWidth()/6, ofGetHeight()/5);
    ofLine(ofGetWidth()/6, ofGetHeight()/2, 5*ofGetWidth()/6, ofGetHeight()/2);
    ofLine(ofGetWidth()/6, 4*ofGetHeight()/5, 5*ofGetWidth()/6, 4*ofGetHeight()/5);
    time = ofGetElapsedTimef();
    cout << time <<endl;
        circle1.display();
    circle2.display();
    circle3.display();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float x = circle1.posX;
    if(x < ofGetWidth()/6 || x > 5*ofGetWidth()/6){
                circle1.velX = -circle1.velX;
            }
    x = x + circle1.velX;
    float y1 = circle1.posY;
    circle1.update(x, y1);
    
    float y2 = ofGetHeight()/2 + 50*sin(x/100);
    circle2.update(x, y2);
    
    float y3 = 4*ofGetHeight()/5 + 50*cos(x/100);
    circle3.update(x, y3);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
