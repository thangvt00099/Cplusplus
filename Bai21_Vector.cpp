#include <iostream>
#include <vector>
using namespace std;

//syntax: vector<dtype> vectorName

int main() {
	vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
	
	// access first element
	cout << cars[0] << endl;
	cout << cars.front() << endl;
	
	// access last element
	cout << cars[cars.size() - 1] << endl;
	cout << cars.back() << endl;
	
	// access element at any index - at() throw error, [] dont show error
	cout << cars.at(2) << endl;
	
	// change element
	cars.at(0) = "Opel";
	cout << cars.at(0) << endl;
	
	// add element - push_back() add element at the end 
	cars.push_back("Tesla");
	cout << cars.back() << endl;
	
	// remove element - pop_back() remove element from the end
	cars.pop_back();
	cout << cars.back() << endl;
	
	// check length
	cout << "Size of vector: " << cars.size() << endl;
	
	// check vector empty
	cout << "Is Empty? " << cars.empty() << endl;
	
	for (int i = 0; i < cars.size(); i++) {
		cout << cars[i] << " ";
	}
	
}
