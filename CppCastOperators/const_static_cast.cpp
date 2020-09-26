#include <iostream>
using namespace std;

void init(int *x)
{
	cout<<"In init method "<<endl;
}

void main(int argc,char *argv[])
{
	int num1 = 10;
	int num2 = 3;

	cout<<"result1 is " << static_cast<double>(num1)/num2 <<endl;

	void init(int *pa);
	const int a1 = 10;

	// init(&a1); 	//error

	init(const_cast<int*>(&a1));
}	
