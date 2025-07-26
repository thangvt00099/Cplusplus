#include <iostream>
#include <set>

// Syntax: set<data_type> set_name
// Default: sort automatically in order ascending
// Unique element

int main() {
	std::set<std::string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
	
	std::set<int> numbers_asc = {1, 7, 3, 2, 5, 9};
	std::cout << "Set ordering ascending: ";
	for (int number : numbers_asc) {
		std::cout << number << " ";
	}
	std::cout << "\n";
	
	// set with sort descending order
	std::set<int, std::greater<int>> numbers_dsc = {1, 7, 3, 2, 5, 9};
	std::cout << "Set ordering descending: ";
	for (int number : numbers_dsc) {
		std::cout << number << " ";
	}
	std::cout << "\n";
	
	// Add new element by insert() method
	cars.insert("Vinfast");
	cars.insert("Tesla");
	cars.insert("Toyota");
	cars.insert("Huyndai");
	std::cout << "Set after insert element: ";
	int count = 1;
	for (std::string car : cars) {
		std::cout << count << "." << car << " | ";
		count++; 
	}
	std::cout << "\n";
	std::cout << "Size of set original: " << cars.size() << "\n";
	
	// Remove element by erase() method
	cars.erase("Volvo");
	cars.erase("Tesla");
	std::cout << "Size of set after remove element: " << cars.size() << "\n";
	
	// Clear() method
	cars.clear();
	std::cout << "Size of set after use clear() method: " << cars.size() << "\n";
	
	// Check empty
	std::cout << "Set empty? " << cars.empty() << "\n";
	
}
