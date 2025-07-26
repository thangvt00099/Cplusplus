#include <iostream>
#include <stack>
using namespace std;

// LIFO => Last in first out. Elements added and removed from the top
// syntax: stack<dtype> stackName
int main() {
	stack<int> nums;
	
	// add element
	nums.push(2);
	nums.push(1);
	nums.push(4);
	nums.push(3);
	nums.push(5);
	nums.push(8);
	nums.push(9);
	nums.push(10);
	
	// access top element
	cout << nums.top() << "\n";
	
	// remove top element
	nums.pop();
	cout << nums.top() << "\n";
	
	// get size
	cout << "Size: " << nums.size() << "\n";
	
	// Check empty
	cout << nums.empty() << "\n";
	
	while (!nums.empty()) {
		cout << nums.top() << " ";
		nums.pop();
	}

}
