#include <iostream>
#include <string>
using namespace std;
// use template to write function or class with different data types

// template function
template <typename T>
T add(T a, T b) {
	return a + b;
}

// template class
template <typename T>
class Box {
	public:
		T value;
		Box(T v) {
			this->value = v;
		}
		
		void show() {
			cout << "Value: " << this->value << "\n";
		}
};

template <typename T1, typename T2>
class Pair {
	public:
		T1 first;
		T2 second;
		
		Pair(T1 a, T2 b) {
			first = a;
			second = b;
		}
		
		void display() {
			cout << "First: " << first << ", Second: " << second << "\n";
		}
};


int main() {
	cout << add<int>(5, 3) << "\n";
	cout << add<double>(2.5, 1.5) << "\n";
	
	Box<int> intBox(5);
	Box<string> strBox("Hello");
	intBox.show();
	strBox.show();
	
	Pair<string, int> person("John", 50);
	Pair<int, double> score(51, 9.5);
	person.display();
	score.display();
	return 0;
}
