#include <iostream>
using namespace std;

int main() {
	auto x = 5;
	cout << x << endl;
	
	int items = 50;
	double cost_per_item = 9.99;
	double total_cost = items * cost_per_item;
	char currency = '$';
	
	cout << "Number of items: " << items << "\n";
	cout << "Cost per item: " << cost_per_item << currency << "\n";
	cout << "Total cost: " << total_cost << currency << "\n";
}
