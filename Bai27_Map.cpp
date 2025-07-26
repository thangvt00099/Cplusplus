#include <iostream>
#include <map>

// Syntax: map<keytype, valuetype> mapName
// at() throw a error message (exception)
// Automatically sorted in ascending order by their keys
// Uniqua key

int main() {
	std::map<std::string, int> people = { {"John", 32}, {"Adele", 45}, {"Bo", 29}};
	
	// Access a map element with obj[key] = value
	std::cout << "John is " << people["John"] << " years old." << "\n";
	
	// Access a map element with at() method
	std::cout << "Adele is " << people.at("Adele") << " years old." << "\n"; 
	
	// Change value with obj[key]
	people["John"] = 50;
	std::cout << "John is " << people["John"] << " years old." << "\n";
	
	// Change value with at() method
	people.at("Bo") = 18;
	std::cout << "Bo is " << people.at("Bo") << " years old." << "\n";
	
	// Add new element with obj[key] = value of insert() method
	people["Jenny"] = 22;
	people["Liam"] = 24;
	people["Kasper"] = 20;
	people["Anja"] = 30;
	
	people.insert({"Doe", 19});
	people.insert({"Messi", 35});
	people.insert({"Ronaldo", 40});
	
	// Remove element with erase() method
	people.erase("Ronaldo");
	people.erase("Messi");
	
	std::cout << "Loop people map: " << "\n";
	for (auto key : people) {
		std::cout << "{" << key.first << ": " << key.second << "}" <<  " | " ;
	}
	std::cout << "\n";
	// Check empty()
	std::cout << "People map is empty? " << people.empty() << "\n";
	
	// size of map
	std::cout << "Size of people map: " << people.size() << "\n";
	
	// Check element exist by count() method
	std::cout << "Ronaldo element is exist? " << people.count("Ronaldo") << "\n";
	
	// Reverse order descending map
	std::map<std::string, int, std::greater<std::string>> reverse_people;
	
	// Copy map
	reverse_people.insert(people.begin(), people.end());
	for (auto key : reverse_people) {
		std::cout << "{" << key.first << ": " << key.second << "}" <<  " | " ;
	}
}
