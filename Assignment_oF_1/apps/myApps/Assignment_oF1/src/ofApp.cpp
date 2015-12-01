#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetFrameRate(60);
    
    nCurveVertices = 7;
    
    curveVertices[0].x = 326;
    curveVertices[0].y = 209;
    curveVertices[1].x = 306;
    curveVertices[1].y = 279;
    curveVertices[2].x = 265;
    curveVertices[2].y = 331;
    curveVertices[3].x = 304;
    curveVertices[3].y = 383;
    curveVertices[4].x = 374;
    curveVertices[4].y = 383;
    curveVertices[5].x = 418;
    curveVertices[5].y = 309;
    curveVertices[6].x = 345;
    curveVertices[6].y = 279;
    
    for (int i = 0; i < nCurveVertices; i++){
        curveVertices[i].bOver 			= false;
        curveVertices[i].bBeingDragged 	= false;
        curveVertices[i].radius = 4;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    float hue = fmodf(ofGetElapsedTimef()*10,255);
    
    ofColor color = ofColor::fromHsb(hue,
                                     ofMap( mouseX, 0,ofGetWidth(), 0,255 ),
                                     ofMap( mouseY, ofGetHeight(),0, 0,255 ) );
    
    ofFill();
    ofSetHexColor(0xe0be21);
    
    //-------------------------------------
    
    
    //------(g)--------------------------------------
    //
    // 		ofBezierVertex
    //
    // 		with ofBezierVertex we can draw a curve from the current vertex
    //		through the the next three vertices we pass in.
    //		(two control points and the final bezier point)
    //
    
    float x0 = 300;
    float y0 = 300;
    float x1 = 300+100*cos(ofGetElapsedTimef()*4.0f);
    float y1 = 300+300*sin(ofGetElapsedTimef()/3.5f);
    float x2 = 600+80*cos(ofGetElapsedTimef()*2.0f);
    float y2 = 300+200*sin(ofGetElapsedTimef()/1.5f);
    float x3 = 700;
    float y3 = 300;
    
    
    ofSetColor( color );
    ofFill();
//    ofFill();
//    ofSetHexColor(0xFF9933);
    ofBeginShape();
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    
    ofEnableAlphaBlending();
    ofFill();
    ofSetColor(0,0,0,40);
    ofCircle(x0,y0,8);
    ofCircle(x1,y1,8);
    ofCircle(x2,y2,8);
    ofCircle(x3,y3,8);
    ofDisableAlphaBlending();
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//------------- -------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    for (int i = 0; i < nCurveVertices; i++){
        float diffx = x - curveVertices[i].x;
        float diffy = y - curveVertices[i].y;
        float dist = sqrt(diffx*diffx + diffy*diffy);
        if (dist < curveVertices[i].radius){
            curveVertices[i].bOver = true;
        } else {
            curveVertices[i].bOver = false;
        }	
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    for (int i = 0; i < nCurveVertices; i++){
        if (curveVertices[i].bBeingDragged == true){
            curveVertices[i].x = x;
            curveVertices[i].y = y;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for (int i = 0; i < nCurveVertices; i++){
        float diffx = x - curveVertices[i].x;
        float diffy = y - curveVertices[i].y;
        float dist = sqrt(diffx*diffx + diffy*diffy);
        if (dist < curveVertices[i].radius){
            curveVertices[i].bBeingDragged = true;
        } else {
            curveVertices[i].bBeingDragged = false;
        }	
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    for (int i = 0; i < nCurveVertices; i++){
        curveVertices[i].bBeingDragged = false;	
    }
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
