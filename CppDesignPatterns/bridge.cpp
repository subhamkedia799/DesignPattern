#include <iostream>
#include <string.h>
using namespace std;
#include "bridge.h"

void RedCircle::drawCircle(int radius, int x, int y) {
  cout << "Drawing Circle [color: red, radius: " <<  radius  
    << ", x: " << x  << ", " << y  << "]" << endl;
}

void GreenCircle::drawCircle(int radius, int x, int y) {
  cout << "Drawing Circle [color: green, radius: " <<  radius  
    << ", x: " << x  << ", " << y  << "]" << endl;   
}

Shape::Shape(DrawAPI *drawAPI)
{
  this->drawAPI = drawAPI;
}

Circle::Circle(int x, int y, int radius, DrawAPI *drawAPI) : 
  Shape(drawAPI) 
{
  this->x = x;  
  this->y = y;  
  this->radius = radius;
}

void Circle::draw() 
{
  drawAPI->drawCircle(radius,x,y);
}