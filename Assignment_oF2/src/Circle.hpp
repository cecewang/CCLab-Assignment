//
//  Circle.hpp
//  oF_Assignment2
//
//  Created by cc on 11/9/15.
//
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include <ofMain.h>

#endif /* Circle_hpp */

class Circle{
    
public:
    Circle(): posX(0), posY(0), velX(0), velY(0){}
    Circle(float x, float y, float vx, float vy);

    float posX, posY, radius;
    float velX, velY;
    
    void setup();
    void display();
    void update(float x, float y);
};
