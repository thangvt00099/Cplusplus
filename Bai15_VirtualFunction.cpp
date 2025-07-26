#include <iostream>
#include <string>
using namespace std;

// virtual keyword just affect to object pointer type
// when use pointer object, use -> to call method
class Animal {
	public:
		void sound() {
			cout << "Animal sound\n";
		}
		
		virtual void testSound() {
			cout << "Test Animal sound\n";
		}
};

class Dog : public Animal {
	public:
		void sound() {
			cout << "Dog barks\n";
		}
		
		void testSound() override{
			cout << "Test Dog sound\n";
		}
};
int main() {
	Animal* a;
	Dog d;
	a = &d;
	a->sound(); // call sound() of Animal when not use virtual keyword, not actual object
	a->testSound(); // call sound() of Dog when use virtual keyword for base Animal class
	return 0;
}
