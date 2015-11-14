#pragma once

#include "ofMain.h"
#include "Circle.hpp"
#define circlenum 12

class ofApp : public ofBaseApp{

	public:
    ofApp(): circle1(ofGetWidth()/6, ofGetHeight()/5, 5, 0), circle2(ofGetWidth()/6, ofGetHeight()/2, 5, 0), circle3(ofGetWidth()/6, 4*ofGetHeight()/5, 5, 0){};
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    int time;
    Circle circle1 ;
    Circle circle2 ;
    Circle circle3 ;
    
		
};
