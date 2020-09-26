#include <iostream>
#include <string.h>
using namespace std;

#define interface struct

interface IRunner {
  virtual void Run() = 0;
};

class Treadmill : public IRunner 
{
  public:
    void Run() {
      cout << "Running on Treadmill " << endl;
    }
};

class Park : public IRunner 
{
  public:
    void Run() {
      cout << "Running in Park " << endl;
    }
};

class ExerciseRoutine 
{
  protected:
    IRunner *runner;
  public:
    void setRunner(IRunner *runner)
    {
      this->runner = runner;
    }
    virtual void workout() = 0;	
};

class WeekdayRoutine : public ExerciseRoutine 
{
  public:
    void workout() 
    {
      cout << "Weekday ";
      runner->Run();
    }
};

class WeekendRoutine : public ExerciseRoutine 
{
  public:
    void workout() 
    {
      cout << "Weekend ";
      runner->Run();
    }
};

void main() {
  ExerciseRoutine *obj = new WeekdayRoutine();
  obj->setRunner(new Treadmill());
  obj->workout();
  obj->setRunner(new Park());
  obj->workout();

  obj = new WeekendRoutine();
  obj->setRunner(new Treadmill());
  obj->workout();
  obj->setRunner(new Park());
  obj->workout();
}