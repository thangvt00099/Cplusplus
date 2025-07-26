#include <iostream> 
#include <thread> // use multithreading
#include <mutex>
std::mutex mtx;

// Syntax: thread thread_name(callable)
//			- thread_name: object of thread class
//			- callable: object like function pointer, function object

// Callable divided into 4 categories:
//			- Function
//			- Lambda expression
//			- Function object
//			- Non-static or static Member Function

// join() - đồng bộ thời điểm kết thúc của các luồng, dữ liệu có thể bị chồng chéo
// 		  - Không chấp nhận tham số, không trả về giá trị
// joinable() - check xem luồng có thể được join hay không (chưa bị join hoặc detach)

// 1. Function pointer
void func(int n) {
	const std::lock_guard<std::mutex> lock(mtx);
	std::cout << "Function pointer: " << n << std::endl;
}

class SumFunctor {
	public:
		int n;
		SumFunctor(int a) : n(a) {}

		void operator()() const {	
			const std::lock_guard<std::mutex> lock(mtx);
			std::cout << "Function object: " << n << std::endl;
		}
};	

class MyClass {
	public:
		// Non-static member function
		void f1(int num) {
			const std::lock_guard<std::mutex> lock(mtx);
			std::cout << "Non-static member function: " << num << std::endl;
		}

		// Static member function
		static void f2(int num) {
			const std::lock_guard<std::mutex> lock(mtx);
			std::cout << "Static member function: " << num << std::endl;
		}
};


int main() {
	// Create thread with func callable
	std::thread t(func, 4);

	int n = 5;
	// 2. Lambda expression
	std::thread t1([](int n) {
		const std::lock_guard<std::mutex> lock(mtx);
		std::cout << "Lambda function: " << n << std::endl;
	}, n);

	// 3. Function object
	std::thread t2(SumFunctor(3));

	// 4. Non-static and static member function
	MyClass obj;

	// Non-static, need object
	std::thread t3(&MyClass::f1, &obj, 6);

	// Static without object
	std::thread t4(&MyClass::f2, 7);

	
	// Main thread wait t thread finish
	t.join();
	if (t.joinable()) {
		std::cout << "Thread can join/detach." << std::endl;
	} else {
		std::cout << "Thread can not join/detach." << std::endl;
	}
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	std::cout << "Main thread finished." << std::endl;
	return 0;	
}
