#include <iostream>

// namespace - avoid name conflict, organize code into logicals group, seperate code
// Syntax: namespace <name_namespace>
namespace MyNamespace { // access member with syntax: namespace::member
	int x = 42;
}

namespace MyNamespace2 {
	int y = 40;
}

using namespace MyNamespace2; // same typedef keyword

int main() {
	std::cout << "Access member MyNamespace: " << MyNamespace::x << "\n";
	std::cout << "Access member MyNamespace2 with using namespace keyword: " << y << "\n";
	return 0;
}
