#include <iostream>
#include <functional> // use to pass lamdba function as an argument to another function
using namespace std;
int myFunction(function<int(int, int)> func) {
	int result1 = func(2, 2);
	int result2 = func(1, 1);
	return result1 + result2;
}

int main() {
	auto message = []() {
		cout << "Hello World!\n";	
	};
	message();
	
	auto add = [](int a, int b) {
		return a + b;
	};
	cout << add(3, 4) << "\n";
	cout << myFunction(add) << "\n";
	
	// using lamdba for loop
	for (int i = 1; i <= 3; i++) {
		auto show = [i]() {
			cout << "Number: " << i << "\n";
		};
		show();
	}
	return 0;
}
