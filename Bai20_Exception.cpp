#include <iostream>
using namespace std;

//catch (...) - xu li bat ki kieu du lieu nao neu khong biet

int main() {
	try {
		int age = 15;
		if (age >= 18) { 
			cout << "Access granted - you are old enough.";
		} else {
			throw(age);
		}
	}
	catch (int myNum) {
		cout << "Access denied - You must be at least 18 years old.\n";
		cout << "Age is: " << myNum;
	}
}
