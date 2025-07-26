#include <iostream>
using namespace std;

enum Level {
	LOW = 1,
	MEDIUM,
	HIGH
};

int main() {
	enum Level myVar = MEDIUM;
	
	switch (myVar) {
		case 1:
			cout << "Low Level";
			break;
		case 2:
			cout << "Medium Level";
			break;
		case 3:
			cout << "High Level";
			break;
	}
}
