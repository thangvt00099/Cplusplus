#include <iostream>
#include <mutex>
#include <thread>

// Syntax: std::mutex mutex_obj_name
// lock() - khóa luồng, chỉ cho phép luồng hiện tại chạy cho tới khi được
//      unlock
// unlock() - mở khóa luồng sau khi thực 1 đoạn code
std::mutex mtx;
int number = 0;

void increment() {
    mtx.lock();
    for (int i = 0; i < 1000; i++) {
        number++;
    }
    mtx.unlock();
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    std::cout << "Number after execution of t1 and t2 is: " << number << std::endl;
    return 0;
}