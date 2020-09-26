#include <iostream>
using namespace std;
#define interface struct

interface Shape
{
  public:
    virtual void accept(class Visitor*) = 0;
};

class Circle: public Shape
{
  public:
    void accept(Visitor*);
    void getRadius() { cout << "Circle::getRadius\n"; }
};

class Square: public Shape
{
  public:
    void accept(Visitor*);
    void getLength() { cout << "Square::getLength\n"; }
};

class Rectangle: public Shape
{
  public:
    void accept(Visitor* v);
    void calculateArea() { cout << "Rectangle::calculateArea\n"; }
};

interface Visitor
{
  public:
    virtual void visit(Circle*) = 0;
    virtual void visit(Square*) = 0;
    virtual void visit(Rectangle*) = 0;
};

class CountVisitor: public Visitor
{
  public:
    CountVisitor() { m_CircleCount = m_SquareCount = m_RectangleCount = 0; }
    void visit(Circle*) { m_CircleCount++; }
    void visit(Square*) { m_SquareCount++; }
    void visit(Rectangle*) { m_RectangleCount++; }

    void report_num()
    {
      cout << "Circles " << m_CircleCount << ", Squares " << m_SquareCount 
        << ", Rectangles " << m_RectangleCount << endl;
    }
  private:
    int m_CircleCount, m_SquareCount, m_RectangleCount;
};

class CallVisitor: public Visitor
{
  public:
    void visit(Circle *cobj) { cobj->getRadius(); }
    void visit(Square *sobj) { sobj->getLength(); }
    void visit(Rectangle *robj) { robj->calculateArea(); }
};

void Circle::accept(Visitor *v)
{
  cout << "Circle ACCEPT" << endl;
  v->visit(this);
}

void Square::accept(Visitor *v)
{
  cout << "Square ACCEPT" << endl;
  v->visit(this);
}

void Rectangle::accept(Visitor *v)
{
  cout << "Rectangle ACCEPT" << endl;
  v->visit(this);
}

int main()
{
  Shape *set[] = 
  {
    new Circle, new Square, new Rectangle, new Circle, 
      new Rectangle, NULL
  };

  CountVisitor countOperation;
  CallVisitor callOperation;
  for (int i = 0; set[i]; i++)
  {
    set[i]->accept(&countOperation);
    set[i]->accept(&callOperation);
  }
  countOperation.report_num();
}
