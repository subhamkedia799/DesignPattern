#include <iostream>
using namespace std;

#define interface struct

interface Shape
{	
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

interface Color {
  virtual void fill() = 0;
};

class red : public Color {
  public:
    void fill() {
      cout << "Filled with red color " << endl;
    }
};

class blue : public Color {
  public:
    void fill() {
      cout << "Filled with blue color " << endl;
    }
};

interface AbstractFactory 
{
    virtual Shape * getShape(char * shape) = 0;
    virtual Color * getColor(char * color) = 0;
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

    Color * getColor(char * colorType)
    {
      return NULL;
    }
};

class ColorFactory : public AbstractFactory 
{
  public:
    Shape * getShape(char * shapeType)
    {      
      return NULL;
    }

    Color * getColor(char * colorType)
    {
      if(colorType == NULL) {
        return NULL;
      }		      
      if(stricmp(colorType, "RED") == 0)
      {
        return new red();       
      }
      else if(stricmp(colorType, "BLUE") == 0)
      {
        return new blue();
      }    
      return NULL;
    }
};

class FactoryProducer 
{
  public:
    static AbstractFactory * getFactory(char *type)
    {   
      if(stricmp(type, "SHAPE") == 0)
      {
         return new ShapeFactory();         
      }   
      else if(stricmp(type, "COLOR") == 0)
      {
         return new ColorFactory();         
      } 
      return NULL;
   }
};

void main() 
{
  AbstractFactory * shapeFactory = FactoryProducer::getFactory("SHAPE");
  Shape * shape1 = shapeFactory->getShape("CIRCLE");
  shape1->draw();

  Shape * shape2 = shapeFactory->getShape("SQUARE");
  shape2->draw();

  AbstractFactory * colorFactory = FactoryProducer::getFactory("COLOR");
  Color *color1 = colorFactory->getColor("RED");
  color1->fill();

  Color *color2 = colorFactory->getColor("BLUE");
  color2->fill();
}
