//
//  Circle.cpp
//  oF_Assignment2
//
//  Created by cc on 11/9/15.
//
//

#include "Circle.hpp"
#include "ofMain.h"

Circle::Circle(float x, float y, float vx, float vy){
    posX = x;
    posY = y;
    velX = vx;
    velY = vy;
}

void Circle::setup(){
    radius = 30;
    
}


void Circle::display(){
    ofSetColor(30);
    ofCircle(posX, posY, radius);
}

void Circle::update(float x, float y){
//    posX += velX;
//    if(posX < ofGetWidth()/6 || posX > 5*ofGetWidth()/6){
//        velX = -velX;
//    }
//    posY += velY;

    posX = x;
    posY = y;
}