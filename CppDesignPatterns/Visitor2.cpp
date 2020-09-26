#include <iostream>
#include <vector>
using namespace std;

class Primitive; 
class Component;
class Composite;

class Visitor
{
  public:
    virtual void visit(Primitive *, Component*) = 0;
    virtual void visit(Composite *, Component*) = 0;
};

class Component
{
    int value;
  public:
    Component(int val)
    {
      value = val;
    }
    virtual void traverse()
    {
      cout << value << " ";
    }
    virtual void accept(Visitor &, Component*) = 0;
};

class Primitive: public Component
{
    vector < Component * > children;
  public:
    Primitive(int val): Component(val){}

    void add(Component *ele)
    {
      children.push_back(ele);
    }

    void accept(Visitor &v, Component *c)
    {
      cout << "Primitive accept " << endl;
      v.visit(this, c);
    }

    void traverse()
    {
      Component::traverse();
      for (int i = 0; i < children.size(); i++)
        children[i]->traverse();
    }
};

class Composite: public Component
{
    vector < Component * > children;
  public:
    Composite(int val): Component(val){}

    void add(Component *ele)
    {
      children.push_back(ele);
    }

    void accept(Visitor &v, Component *c)
    {
      cout << "Composite accept " << endl;
      v.visit(this, c);
    }

    void traverse()
    {
      Component::traverse();
      for (int i = 0; i < children.size(); i++)
        children[i]->traverse();
    }
};

class AddVisitor: public Visitor
{
  public:
    void visit(Primitive *node, Component* c)
    {
      node->add(c);
    }
    void visit(Composite *node, Component *c)
    {
      node->add(c);
    }
};

int main()
{
  Component *nodes[2];

  nodes[0] = new Composite(1);
  nodes[1] = new Primitive(2);

  AddVisitor addVisitor;
  nodes[0]->accept(addVisitor, new Primitive(3));
  nodes[0]->accept(addVisitor, new Primitive(4));
  nodes[1]->accept(addVisitor, new Primitive(5));
  nodes[1]->accept(addVisitor, new Primitive(6));

  for (int i = 0; i < 2; i++)
  {
    nodes[i]->traverse();
    cout << endl;
  }
}