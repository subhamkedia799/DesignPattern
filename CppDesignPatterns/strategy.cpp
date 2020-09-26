#include <iostream>
#include <string.h>
using namespace std;

#define interface struct

interface Strategy {
  virtual int doOperation(int num1, int num2) = 0;
};

class OperationAdd : public Strategy {
  public:
    int doOperation(int num1, int num2) {
      return num1 + num2;
    }
};

class OperationSubtract : public Strategy {
  public:
    int doOperation(int num1, int num2) {
      return num1 - num2;
    }
};

class OperationMultiply : public Strategy {
  public:
    int doOperation(int num1, int num2) {
      return num1 * num2;
    }
};

class Context {
  Strategy *strategy;

  public:
    Context(Strategy *strategy){
      this->strategy = strategy;
    }

    int executeStrategy(int num1, int num2){
      return strategy->doOperation(num1, num2);
    }
};

void main() {
  Context *context = new Context(new OperationAdd());
  cout << context->executeStrategy(10, 5) << endl;
  context = new Context(new OperationSubtract());
  cout << context->executeStrategy(10, 5) << endl;
  context = new Context(new OperationMultiply());
  cout << context->executeStrategy(10, 5) << endl;
}