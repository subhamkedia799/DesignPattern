#include <iostream>
using namespace std;

#define interface struct

interface IData 
{	
  virtual void addData() = 0;
  virtual void getData() = 0;
  virtual void deleteData() = 0;
  virtual void updateData() = 0;
};

class fileData : public IData {
  public:
    void addData() {
      cout << "fileData addData invoked " << endl;
    }
    void getData() {
      cout << "fileData getData invoked " << endl;
    }
    void deleteData() {
      cout << "fileData deleteData invoked " << endl;
    }
    void updateData() {
      cout << "fileData updateData invoked " << endl;
    }
};

class dbData : public IData {
  public:
    void addData() {
      cout << "dbData addData invoked " << endl;
    }
    void getData() {
      cout << "dbData getData invoked " << endl;
    }
    void deleteData() {
      cout << "dbData deleteData invoked " << endl;
    }
    void updateData() {
      cout << "dbData updateData invoked " << endl;
    }
};

void main() 
{
  IData *obj = new fileData();
  obj->addData();
  obj->getData();
  obj->updateData();
  obj->deleteData();

  delete obj;
  obj = new dbData();
  obj->addData();
  obj->getData();
  obj->updateData();
  obj->deleteData();
}