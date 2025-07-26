#include <iostream>
#include <string>
using namespace std;
// new - manage memory
// delete - delete when it's done

int main() {
	int myInt;
	long long myLong;
	float myFloat;
	double myDouble;
	char myChar;
	string myString;
	bool myBoolean;
	
	// using sizeof() to check memory
	cout << sizeof(myInt) << "\n";
	cout << sizeof(myLong) << "\n";
	cout << sizeof(myFloat) << "\n";
	cout << sizeof(myDouble) << "\n";
	cout << sizeof(myString) << "\n";
	cout << sizeof(myChar) << "\n";
	cout << sizeof(myBoolean) << "\n";
	
	int* ptr = new int;
	*ptr = 35;
	cout << *ptr << "\n";
	delete ptr;
	cout << *ptr << "\n";
	
	// Example using new, delete for Array
	int numGuests;
	cout << "How many guest? ";
	cin >> numGuests;
	
	if (numGuests <= 0) {
		cout << "Number of guest must be at least 1.\n";
		return 0;
	}
	// Create memory space for numGuest when you dont know how many
	string* guests = new string[numGuests];
	for (int i = 0; i < numGuests; i++) {
		cout << "Enter name for guest " << i + 1 << ": ";
		cin >> guests[i];
	}
	
	cout << "\nGuests checked in: \n";
	for (int i = 0; i < numGuests; i++) {
		cout << guests[i] << "\n";
	}
	
	delete[] guests;
	return 0;
}
