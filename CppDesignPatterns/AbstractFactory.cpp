#include <iostream>
using namespace std;

class Shape 
{	
  public:
    virtual void draw() = 0;
};

class Square : public Shape 
{
  public:
    void draw() {
      cout << "Inside Square::draw() method." << endl;
  }
};

class Circle : public Shape 
{
  public:
    void draw() {
      cout << "Inside Circle::draw() method." << endl;
  }
};

class AbstractFactory 
{
  public:
   virtual Shape * getShape(char * shape) = 0;
};

class ShapeFactory : public AbstractFactory 
{
  public:
    Shape * getShape(char * shapeType)
    {   
      if(shapeType == NULL) {
        return NULL;
      }		      
      if(stricmp(shapeType, "CIRCLE") == 0)
      {
        return new Circle();       
      }
      else if(stricmp(shapeType, "SQUARE") == 0)
      {
        return new Square();
      }    
      return NULL;
    }
};

class FactoryProducer 
{
  public:
    static AbstractFactory * getFactory(char * choice)
    {   
      if(stricmp(choice, "SHAPE") == 0)
      {
         return new ShapeFactory();         
      }   
      return NULL;
   }
};

void main() 
{
  //get shape factory
  AbstractFactory * shapeFactory = FactoryProducer::getFactory("SHAPE");

  //get an object of Shape Circle
  Shape * shape1 = shapeFactory->getShape("CIRCLE");

  //call draw method of Shape Circle
  shape1->draw();

  //get an object of Shape Square 
  Shape * shape2 = shapeFactory->getShape("SQUARE");

  //call draw method of Shape Square
  shape2->draw();
}