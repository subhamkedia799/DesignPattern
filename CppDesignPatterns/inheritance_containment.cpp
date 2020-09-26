#include <iostream>
using namespace std;

class oneI {
  public:
    int add(int x, int y)
    {
      return x + y;
    }
};

class twoI : public oneI {
  public:
    int mult(int x, int y)
    {
      return x * y;
    }
};

class oneC {
  public:
    int add(int x, int y)
    {
      return x + y;
    }
};

class twoC {
  oneC obj;
  public:
    void callbaseMethod()
    {
      cout << obj.add(10, 20) << endl;
    }
    int mult(int x, int y)
    {
      return x * y;
    }
};

void main() 
{
  twoI objI;
  int result;
  result = objI.add(3, 4);
  cout << result << endl;
  result = objI.mult(3, 4);
  cout << result << endl;

  twoC objC;
  objC.callbaseMethod();
  result = objC.mult(10, 20);
  cout << result << endl;
}

// Make the following changes:
// 1) Add a subtract method in oneI and oneC
// 2) Update the signature of add in oneI and oneC (add third argument)