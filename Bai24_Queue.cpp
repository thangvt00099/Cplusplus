#include <iostream>
#include <queue>
using namespace std;

// FIFO - First In First Out
// Syntax - queue<dtype> queueName
int main() {
	queue<string> cars;
	
	// Add element
	cars.push("Volvo");
	cars.push("BMW");
	cars.push("Ford");
	cars.push("Mazda");
	
	cout << cars.size() << endl;
	
	// Access the front element
	cout << cars.front() << endl;
	
	// Access the back element
	cout << cars.back() << endl;
	
	// Remove element - pop() will remove front element
	cars.pop();
	cout << cars.front() << endl;
	
	while (!cars.empty()) {
		cout << cars.front() << " ";
		cars.pop();
	}
	
	
}
