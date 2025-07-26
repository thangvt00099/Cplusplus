#include <iostream>
#include <string>
using namespace std;

int main() {
	string greeting = "Hello";
	cout << greeting << "\n";
	
	string firstName = "John";
	string lastName ="Doe";
	
	// Using + operator for concat string
	string fullName = firstName + " " + lastName;
	cout << "Full name: " << fullName << "\n";
	cout << "First character: " << fullName[0] << "\n";
	cout << "Last character: " << fullName[fullName.length() - 1] << "\n";
	
	// Access character by using at() method
	cout << "At method: " << fullName.at(2) << "\n";
	
	// get length by using length()
	cout << "Length method: " << fullName.length() << "\n";
	
	// get length by using size() - alias of length()
	cout << "Size method: " << fullName.size() << "\n";
	
	// Using append function
	string firstName2(" Thang");
	string lastName2("Tran");
	string midName(" Vu");
	string hoVaTen = lastName2.append(midName.append(firstName2));
	cout << "Ho va ten: " << hoVaTen << "\n";
	
	// Using backslash 
	string txt = "We are the so-called \"Vikings\" from the north.";
	cout << "Backslash: " << txt << "\n";
	
	string myFullName;
	cout << "Type my full name: ";
	getline (cin, myFullName);
	cout << "My name is: " << myFullName << "\n";
		
}
