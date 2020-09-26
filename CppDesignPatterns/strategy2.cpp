#include <iostream>
#include <string.h>
using namespace std;

#define interface struct

interface IStrategy {
  virtual void Workout() = 0;
};

class CardioStrategy : public IStrategy 
{
  public:
    void Workout() {
      cout << "Cardio workout " << endl;
    }
};

class AerobicsStrategy : public IStrategy 
{
  public:
    void Workout() {
      cout << "Aerobics workout " << endl;
    }
};

class ExerciseRoutine {
  IStrategy *strategy;

  public:
    ExerciseRoutine(IStrategy *strategy){
      this->strategy = strategy;
    }

    void executeStrategy(){
      return strategy->Workout();
    }
};

void main() {
  ExerciseRoutine *context = new ExerciseRoutine(new CardioStrategy());		
  context->executeStrategy();

  context = new ExerciseRoutine(new AerobicsStrategy());		
  context->executeStrategy();
}