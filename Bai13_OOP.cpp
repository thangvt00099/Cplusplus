#include <iostream>
#include <string>
using namespace std;

class MyClass {
	public:
		int myNum;
		string myString;
};

// Challenge 1
class Book {
	private:
		string title;
		string author;
		int year;
	
	public:
		Book() {
			this->title = "";
			this->author = "";
			this->year = 0;
		}
		
		Book(string title, string author, int year) {
			this->title = title;
			this->author = author;
			this->year = year;
		}
		
		void printInfoBook();
};

void Book::printInfoBook() {
	cout << "Title: " << this->title << "\nAuthor: " << this->author << "\nYear: " << this->year << endl;
}

// Challenge 2
class Dog {
	public:
		void bark();
};

void Dog::bark() {
	cout << "Woof!";
}

int main() {
	MyClass myObj;
	myObj.myNum = 15;
	myObj.myString = "Some text";
	
	cout << myObj.myNum << "\n";
	cout << myObj.myString << "\n";
	
	// Challenge Task 1
	Book firstBook("Matilda", "Roald Dahl", 1988);
	Book secondBook("The Giving Tree", "Shel Silverstein", 1964);
	firstBook.printInfoBook();
	secondBook.printInfoBook();
	
	// Challenge Task 2
	Dog firstDog;
	firstDog.bark();
	
	return 0;
}
