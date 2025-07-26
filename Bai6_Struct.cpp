#include <iostream>
#include <string>
using namespace std;
struct {
	int myNum;
	string myString;
} myStructure; // Name of struct

struct {
	string brand;
	string model;
	int year;
} myCar1, myCar2; // Name of struct

// Create struct as a data type
struct name {
	string firstName;
	string lastName;
};

// Challenge Task
struct student {
	string name;
	int age;
	char grade;
};

int main() {
	myStructure.myNum = 1;
	myStructure.myString = "Hello World!";
	cout << myStructure.myNum << "\n";
	cout << myStructure.myString << "\n";
	
	myCar1.brand = "BMW";
	myCar1.model = "X5";
	myCar1.year = 1999;
	
	myCar2.brand = "Ford";
	myCar2.model = "Mustang";
	myCar2.year = 1969;
	
	cout << myCar1.brand << " " << myCar1.model << " " << myCar1.year << "\n";
	cout << myCar2.brand << " " << myCar2.model << " " << myCar2.year << "\n";	
	
	name fullName1;
	fullName1.firstName = "John";
	fullName1.lastName = "Doe";
	
	name fullName2;
	fullName2.firstName = "Cristiano";
	fullName2.lastName = "Ronaldo";
	
	cout << fullName1.firstName << " " << fullName1.lastName << "\n";
	cout << fullName2.firstName << " " << fullName2.lastName << "\n";
	
	student firstStudent;
	firstStudent.name = "Liam";
	firstStudent.age = 35;
	firstStudent.grade = 'A';
	cout << "Name: " << firstStudent.name << "\n";
	cout << "Age: " << firstStudent.age << "\n";
	cout << "Grade: " << firstStudent.grade << "\n";
}
