#include <iostream>
#include <thread>
#include <chrono>

// detach() - tách 1 luồng chạy độc lập, tự thực thi và giải phóng 
//          tài nguyên khi kết thúc luôn trong khi các luồng khác
//          vẫn chạy song song

void threadFunction() {
    std::cout << "Detached thread executing..." << std::endl;
    std::this_thread::sleep_for(
        std::chrono::seconds(2)
    );
    std::cout << "Detached thread completed." << std::endl;
}

int main() {
    std::thread detachedThread(threadFunction);
    detachedThread.detach();

    std::cout << "Main thread continuting..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(3));

    return 0;
}