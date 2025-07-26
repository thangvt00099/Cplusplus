#include <iostream>
#include <deque>
#include <string>

// Syntax: deque<data_type> dequeName
// Using at() method when get element because it throw error messa
int main() {
	std::deque<std::string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
	
	// Access of element
	std::cout << "First Element: " << cars[0] << "\n";
	std::cout << "Second Element: " << cars[1] << "\n";
	
	// Get first element by front() method
	std::cout << "Get first element by front() method: " << cars.front() << "\n";
	
	// Get last element by back() method
	std::cout << "Get last element by back() method: " << cars.back() << "\n";
	
	// Access element by at() method
	std::cout << "Get element by at() method: " << cars.at(2) << "\n";
	
	// Add element head by push_front() method
	cars.push_front("Vinfast");
	
	// Add element tail by push_back() method
	cars.push_back("Huyndai");
	
	// Remove element first by pop_front() method
	cars.pop_front();
	
	// Remove element last by pop_back() method
	cars.pop_back();
	
	std::cout << "Print element of cars: ";
	int count = 1;
	for (std::string car : cars) {
		std::cout << count << "."<< car << " | ";
		count++;
	}
	std::cout << "\n";
	
	// Size of deque
	std::cout << "Size of deque: " << cars.size() << "\n";
	
	// Check deque empty
	std::cout << "Deque is empty? " << cars.empty() << "\n";
}
