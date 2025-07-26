#include <iostream>
#include <vector>
#include <algorithm> // sort and search elements in a data structure

// Support iterator (vector, list, deque, map and set) - stack and queue do not

int main() {
	std::vector<std::string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
	
	// Create a vector iterator
	std::vector<std::string>::iterator it;
	
	// add, modify, remove element => use iterator
	std::cout << "Loop by using iterator: \n";
	for (auto it = cars.begin(); it != cars.end(); it++) {
		if (*it == "BMW" && it != cars.begin()) {
			it = cars.erase(it);
			it--;
		} else {
			std::cout << *it << "\n";
		}
	}
	
	// for-each just view element
	std::cout << "Loop by using for-each: \n";
	for (std::string car : cars) {
		std::cout << car << "\n";
	}
	
	// Iterator reverse with rbegin(), rend()
	std::cout << "Iterator reverse: \n";
	for (auto it = cars.rbegin(); it != cars.rend(); it++) {
		std::cout << *it << "\n";
	}
	
	// Sort cars ascending
	std::sort(cars.begin(), cars.end());
	std::cout << "Sort with begin, end for parameters: \n";
	for (std::string car : cars) {
		std::cout << car << "\n";
	}
	
	std::vector<int> numbers = {1, 7, 3, 5, 9, 2};
	std::sort(numbers.begin(), numbers.end());
	std::cout << "Sort numbers ascending: \n";
	for (int number : numbers) {
		std::cout << number << " ";
	}
	std::cout << "\n";
	
	std::sort(numbers.rbegin(), numbers.rend());
	std::cout << "Sort numbers descending: \n";
	for (int number : numbers) {
		std::cout << number << " ";
	}
	std::cout << "\n";
	
}
