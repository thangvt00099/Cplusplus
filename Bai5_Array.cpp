#include <iostream>
#include <vector>
using namespace std;

int main() {
	string cars[5] = {"Volvo", "BMW", "Ford", "Mazda", "Tesla"};
	
	for (int i = 0; i < 5; i++) {
		cout << i << " = " << cars[i] << "\n";
	}
	
	int myNum[3] = {10, 20, 30};
	for (int i : myNum) {
		cout << i << "\n";
	}
	cout << myNum[2] << "\n";
	
	vector<string> names = {"Thang", "Khoa", "Khanh", "Tuan"};
	names.push_back("Duong");
	
	for (string name : names) {
		cout << name << " ";
	}
	cout << "\n";
	
	// Multidimensional Arrays
	string letters[2][4] = {{"A", "B", "C", "D"}, {"E", "F", "G", "H"}};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			cout << letters[i][j] << "\n";
		}
	}
	
}
