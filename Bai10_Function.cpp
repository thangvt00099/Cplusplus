#include <iostream>
#include <string>
using namespace std;
struct Car {
	string brand;
	int year;
};

// Function declaration
void myFunction(string fname);
void myCountry(string country = "Norway");
void myInfo(string fname, int age);
int add(int x, int y);
void swapNums(int &x, int &y);
void modifyStr(string &str);
void structFunction(Car c);
void updateYearCar(Car &c);


int main() {
	myFunction("Liam");
	myFunction("Jenny");
	myFunction("Anja");
	myCountry("Vietnamese");
	myCountry("India");
	myCountry();
	myInfo("Liam", 23);
	myInfo("Jenny", 25);
	myInfo("Anja", 30);
	cout << add(5, 3) << "\n";
	
	int firstNum = 10;
	int secondNum = 20;
	cout << "Before swap: " << firstNum << " " << secondNum << "\n";
	swapNums(firstNum, secondNum);
	cout << "After swap: " << firstNum << " " << secondNum << "\n";
	
	string greeting = "Hello";
	modifyStr(greeting);
	cout << greeting << "\n";
	
	Car myCar = {"Toyota", 2020};
	updateYearCar(myCar);
	structFunction(myCar);
	return 0;
}

// Function definition
void myFunction(string fname) {
	cout << fname << " Refsnes\n";
}

void myCountry(string country) {
	cout << country <<"\n";
}

void myInfo(string fname, int age) {
	cout << fname << " Refsnes. " << age << " years old. \n";
}

void swapNums(int &x, int &y) {
	int z = x;
	x = y;
	y = z;
}

void modifyStr(string &str) {
	str += " World!";
}

int add(int x, int y) {
	return x + y;
}

void structFunction(Car c) {
	cout << "Brand: " << c.brand << ", Year: " << c.year << "\n";
}

void updateYearCar(Car &c) {
	c.year++;
}

