#include <iostream>
#include <memory> // using smartpointer

// Smart pointers are implemented as template => any datatype
// auto_ptr - khong dung tu phien ban C++11 va bi xoa tu C++17
// unique_ptr - chi co 1 con tro tro vao doi tuong tai 1 thoi diem, khong the copy,
//				chi chuyen doi quyen so huu bang phuong thuc move()
// shared_ptr - co nhieu hon 1 con tro tro vao 1 doi tuong tai 1 thoi diem,
//				su dung use_count() de dem so luong con tro tham chieu vao doi tuong
// weak_ptr - ngan chan vong lap so huu cua shared_ptr
class Rectangle {
	int lenght;
	int breadth;
	
	public:
		Rectangle(int l, int b) : lenght(l), breadth(b) {}
		
		int area() {
			return this->lenght * this->breadth;
		}
};

int main() {
	// Unique_ptr
	std::unique_ptr<Rectangle> P1(new Rectangle(10, 5));
	std::cout << "Unique_ptr P1 access area(): " << P1->area() << std::endl;
	
	std::unique_ptr<Rectangle> P2;
	
	// Tranfer ownership of unique_ptr P1 into P2
	P2 = std::move(P1);
	std::cout << "P2 access area after tranfer ownership from P1: " << P2->area() << std::endl;
	
	// Shared_ptr
	std::shared_ptr<Rectangle> P3(new Rectangle(3, 4));
	std::cout << "Shared_ptr P3 access area(): " << P3->area() << std::endl;
	
	std::shared_ptr<Rectangle> P4;
	P4 = P3;
	std::cout << "Shared_ptr P4 access area(): " << P4->area() << std::endl;
	std::cout << "Count pointers refer to object Rectangle(3, 4): " << P3.use_count() << std::endl;
	
	// Weak_ptr
	std::shared_ptr<Rectangle> P5 = std::make_shared<Rectangle>(10, 5);
	std::weak_ptr<Rectangle> P6 = P5;
	std::cout << P5->area() << std::endl;
 	std::cout << P5.use_count() << std::endl;
	
	return 0;
}
