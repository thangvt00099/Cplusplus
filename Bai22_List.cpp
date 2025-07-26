#include <iostream>
#include <list>
using namespace std;
// syntax: list<dtype> listName
// Because list not access element by index => loop list by for-each

int main() {
	list<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
	
	// get first element
	cout << cars.front() << endl;
	
	// get last element
	cout << cars.back() << endl;
	
	// Add element at the beginning
	cars.push_front("Tesla");
	
	// Add element at the end
	cars.push_back("Vinfast");
	
	cout << cars.front() << endl;
	cout << cars.back() << endl;
	cout << "List before remove element: \n";
	for (string car : cars) {
		cout << car << " | ";
	}
	cout << "\n";
	
	// Remove element at the beginning
	cars.pop_front();
	
	// Remove element at the end
	cars.pop_back();
	
	cout << "List after remove element: \n";
	for (string car : cars) {
		cout << car << " | ";
	}
	cout << "\n";
}
