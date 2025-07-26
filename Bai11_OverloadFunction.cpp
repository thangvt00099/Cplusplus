#include <iostream>
using namespace std;

// Without function overloading
int plusFuncInt(int x, int y);
double plusFuncDouble(double x, double y);

// Function overloading
int plusFunc(int a, int b);
double plusFunc(double a, double b);



int main() {
	int firstNum = plusFuncInt(3, 5);
	double secondNum = plusFuncDouble(3.2, 5.3);
	cout << "First num: " << firstNum << "\n" << "Second num: " << secondNum << "\n";
	
	int thirdNum = plusFunc(2, 2);
	double fourNum = plusFunc(2.2, 2.3);
	cout << "Third num: " << thirdNum << "\n" << "Four num: " << fourNum << "\n";
}

int plusFuncInt(int x, int y) {
	return x + y;
}

double plusFuncDouble(double x, double y) {
	return x + y;
}

int plusFunc(int a, int b) {
	return a + b;
} 

double plusFunc(double a, double b) {
	return a + b;
}
