#include <iostream>
#include <string>

using namespace std;

// friend function -> can access private data when use friend function
// friend function not a member of class
class Employee {
	private:
		int salary;
	
	public:
		Employee(int s) {
			this->salary = s;
		}
		
		// friend function
		friend void displaySalary(Employee emp);
};

void displaySalary(Employee emp) {
	cout << "Salary: " << emp.salary;
}

int main() {
	Employee myEmp(50000);
	displaySalary(myEmp);
	return 0;
}
