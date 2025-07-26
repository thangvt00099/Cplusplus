#include <iostream>

// Function template
template <typename T>
T myMax(T x, T y) {
	return (x > y) ? x : y;
}

// Class template
template <typename T>
class Geek {
	public:
		T x;
		T y;
	
		Geek(T val1, T val2) : x(val1), y(val2) {}
		
		void getValue() {
			std::cout << x << " " << y << std::endl;
		}
};

// multiple type
template <typename T1, typename T2, typename T3>
class GeekMulti {
	public:
		T1 x;
		T2 y;
		T3 z;
		
		GeekMulti(T1 val1, T2 val2, T3 val3) : x(val1), y(val2), z(val3) {}
		
		void getValue() {
			std::cout << x << " " << y << " " << z << std::endl;
		}
};

// Template variable (since C++14) with constexpr
template <typename T> constexpr T getPi() {
	return T(3.14159);
}

// Default template arguments
template <typename T1, typename T2 = double, typename T3 = std::string>
class GeekDefault {
	public:
		T1 x;
		T2 y;
		T3 z;
		
		GeekDefault(T1 val1, T2 val2, T3 val3) : x(val1), y(val2), z(val3) {}
		
		void getValues() {
			std::cout << x << " " << y << " " << z << std::endl;
		}
}; 

int main() {
	// Call myMax for int
	std::cout << myMax<int>(3, 7) << std::endl;
	
	// Call myMax for double
	std::cout << myMax<double>(3.0, 7.0) << std::endl;
	
	// Call myMax for char
	std::cout << myMax<char>('g', 'e') << std::endl;
	
	// Create instance Geek class
	Geek<int> intGeek(10, 20);
	Geek<double> doubleGeek(3.14, 6.28);
	intGeek.getValue();
	doubleGeek.getValue();
	
	// Create instance GeekMulti class with multi parameter template
	GeekMulti<int, double, std::string> intDoubleStringGeek(10, 20.0, "TVT");
	GeekMulti<char, float, bool> charFloatBoolGeek('t', 3.14, true);
	intDoubleStringGeek.getValue();
	charFloatBoolGeek.getValue();
	
	// Template variable
	std::cout << "PI as float: " << getPi<float>() << std::endl;
	std::cout << "PI as double: " << getPi<double>() << std::endl;
	
	// Create instance GeekDefault with default template arguments
	GeekDefault<int, float, std::string> intFloatStringGeek(10, 5.57f, "Hello");
	GeekDefault<bool> boolGeek(true, 3.22, "TVT");
	intFloatStringGeek.getValues();
	boolGeek.getValues();
	
	return 0;
}
