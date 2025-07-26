#include <iostream>
using namespace std;

int main() {
	const int myNum = 5;
	double myFloatNum = 5.99;
	char myLetter = 'D';
	string myText = "Hello";
	bool myBoolean = true;
	
	cout << "myNum = " << myNum << endl;
	cout << "myFloatNum = " << myFloatNum << endl;
	cout << "myLetter = " << myLetter << endl;
	cout << "myText = " << myText << endl;
	cout << "myBoolean = " << myBoolean << endl;
	
	int myAge = 35;
	cout << "I am " << myAge << " years old\n";
	
	int x = 5, y = 6;
	int sum = x + y;
	cout << "sum = " << sum << "\n";
	
	int a = 5, b = 6, z = 50;
	cout << a + b + z << endl;
	
	int minutesPerHour = 60;
	cout << "MinutesPerHour: " << minutesPerHour << endl;
	
	int studentID = 15;
	int studentAge = 23;
	float studentFee = 75.25;
	char studentGrade = 'B';
	
	cout << "Student ID: " << studentID << endl;
	cout << "Student Age: " << studentAge << endl;
	cout << "Student Fee: " << studentFee << endl;
	cout << "Student Grade: " << studentGrade << endl;
	
	int length = 4;
	int width = 6;
	
	int area = length * width;
	
	cout << "Length is: " << length << "\n";
	cout << "Width is: " << width << "\n";
	cout << "Area of the rectangle is: " << area << "\n";
	
	return 0;
}
