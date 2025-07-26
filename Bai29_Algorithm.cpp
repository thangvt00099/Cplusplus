#include <iostream>
#include <algorithm>

// used to solve problems by sorting, searching and manipulating data structure
// Syntax: sort(start_iterator, end_iterator)
//		   find(start_iterator, end_iterator, value)
int main() {
	std::vector<int> numbers = {1, 7, 3, 9, 5, 2};
	
	// Sort
	std::sort(numbers.begin(), numbers.end());
	std::cout << "Sort numbers: \n";
	for (auto it = numbers.begin(); it != numbers.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n";
	
	// Sort reverse
	std::sort(numbers.rbegin(), numbers.rend());
	std::cout << "Sort reverse numbers: \n";
	for (auto it = numbers.begin(); it != numbers.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n";
	
	// Sort subarray
//	std::sort(numbers.begin() + 2, numbers.end());
//	std::cout << "Sort from element index = 3 => end: \n";
//	for (auto it = numbers.begin(); it != numbers.end(); it++) {
//		std::cout << *it << " ";
//	}
//	std::cout << "\n";
//	
	// find => return iterator point refer to value found
	auto it = std::find(numbers.begin(), numbers.end(), 3);
	if (it != numbers.end()) {
		std::cout << "The number 3 was found. \n";
	} else {
		std::cout << "The number 3 was not found. \n";
	}
	
	// upper_bound() - search first element greater than a specific value - iterator must be sort ascending
	// because upper_bound use binary_search for find ( it is >)
	
	// lower_bound() same upper_bound but it is >=
	std::vector<int> numbers2;
	numbers2.assign(numbers.begin(), numbers.end());
	std::sort(numbers2.begin(), numbers2.end());
	auto first_greater = std::upper_bound(numbers2.begin(), numbers2.end(), 5);
	std::cout << "First element greater than 5: " << *first_greater << "\n";
	
	// min_element() - find smallest element
	auto min_el = std::min_element(numbers2.begin(), numbers2.end());
	std::cout << "Min element: " << *min_el << "\n";
	
	// max_element() - find biggest element
	auto max_el = std::max_element(numbers2.begin(), numbers2.end());
	std::cout << "Max element: " << *max_el << "\n";
	
	// copy() - copy iterator | Syntax: copy(another.begin(), another.end(), current.begin())
	std::vector<int> copiedNumber(numbers2.size());
	std::copy(numbers2.begin(), numbers2.end(), copiedNumber.begin());
	std::cout << "Vector copiedNumeber: \n";
	for (auto it = copiedNumber.begin(); it != copiedNumber.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n";
	
	// fill all element with a value
	std::vector<int> fillVector(6);
	std::fill(fillVector.begin(), fillVector.end(), 35);
	std::cout << "fillVector: \n";
	for (auto it = fillVector.begin(); it != fillVector.end(); it++) {
		std::cout << *it << " ";
	}
	
	

	
	
}
