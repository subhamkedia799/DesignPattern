# include <iostream>
# include <list>

using namespace std;

class Subject;

class Observer {
   protected :
     Subject *subject;
   public:
     virtual void update() = 0;
};

class Subject {	
  private:
    list <Observer *> observers;

  public:        
    void attach(Observer *o){
      observers.push_back(o);		
    }

    void detach (Observer* o) {
      observers.remove(o);
    }

    void notifyAllObservers()
    {
      list <Observer *>::iterator o_Iter;

      for (o_Iter = observers.begin(); o_Iter != observers.end(); o_Iter++)
      {
        if(*o_Iter != 0)
        {
            (*o_Iter)->update();
        }
      } 	
    }
};

class ConcreteSubject: public Subject {	
  private:
    int state;

  public:        
    int getState() {
      return state;
    }   

    void setState(int changedData) {
      state = changedData;
      notifyAllObservers();
    }
};

class HexadecimalObserver : public Observer
{
  private:
    ConcreteSubject* _subject;
  public:
    HexadecimalObserver(ConcreteSubject *sub)
    {
      _subject = sub;
      _subject->attach(this);
    }

    HexadecimalObserver()
    {
      this->_subject = NULL;
    }

    void update() {
      cout << "Hexadecimal String: " <<  hex <<  _subject->getState() << endl; 
    }
};

class OctalObserver  : public Observer
{
  private:
    ConcreteSubject* _subject;

  public:
    OctalObserver (ConcreteSubject *sub){
      _subject = sub;
      _subject->attach(this);
    }

    OctalObserver()
    {
      this->_subject = NULL;
    }

    void update() {
      cout << "Octal String: " <<  oct <<  _subject->getState() << endl; 
    }
};

void main()
{
  ConcreteSubject *subject = new ConcreteSubject();
  Observer *Octobj = new OctalObserver(subject);
  Observer *hexaObj = new HexadecimalObserver(subject);
  subject->setState(25);
  subject->setState(50);
  subject->detach(Octobj);
  subject->setState(100);
  subject->detach(hexaObj);
  subject->setState(200);
}
