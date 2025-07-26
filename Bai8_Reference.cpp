#include <iostream>
#include <string>
using namespace std;

// &food => memory address of food
// * => store the address
// pointer variable has to same data type with your variable
int main() {
	string food = "Pizza";
	string &meal = food; // refer to food
	cout << food << "==" << meal << endl;
	cout << "Memory address of food: " << &food << "\n";
	
	string* ptr = &food;
	cout << "Memory address of food stored by pointer: " << ptr << "\n";
	
	cout << "Compare &food and *ptr: " << (&food == ptr) << "\n";
	
	int myAge = 22;
	cout << "Memory address of myAge: " << &myAge << "\n";
	int* myAgePtr = &myAge;
	cout << "Memory address of myAge stored by pointer: " << myAgePtr << "\n";
	cout << "Value of myAge by pointer: " << *myAgePtr << "\n";
	
	// change pointer value will change value original
	*myAgePtr = 25;
	cout << "Value of myAge changed by pointer when pointer value changed: " << myAge << "\n";
}
