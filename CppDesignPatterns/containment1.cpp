#include <iostream>
using namespace std;

#define interface struct

interface IText 
{	
  virtual char * getText() = 0;
};

class htmlText : public IText {
  public:
    char * getText() {
      return "html text";
    }
    void method1() {}
};

class jsonText : public IText {
  public:
    char * getText() {
      return "json text";
    }
    void method2() {}
};

class report {
  IText *obj;

  public:
  char * getReportText(int type)
  { 
    if(type == 1)
    {
      obj = new htmlText();
      return obj->getText();
    }
    else if(type == 2)
    {
      obj = new jsonText();
      return obj->getText();
    }
  }
};

void main() 
{
  report obj;
  cout << obj.getReportText(1) << endl;
  cout << obj.getReportText(2) << endl;
}