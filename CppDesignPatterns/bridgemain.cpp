#include <iostream>
#include <string.h>
using namespace std;
#include "bridge.h"

void main() {
  Shape *redCircle  = new Circle(100,100, 10, new RedCircle());
  Shape *greenCircle  = new Circle(100,100, 10, new GreenCircle());

  redCircle->draw();
  greenCircle->draw();
}

// cl -c bridge.cpp
// cl -c bridgemain.cpp
// cl bridge bridge.obj bridgemain.obj
