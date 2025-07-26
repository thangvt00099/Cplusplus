#include <iostream>
#include <ctime>
using namespace std;

// 2 cach luu tru time
// 1. time_t cho timestamp
// 2. struct tm cho datetime structures

int main() {
	struct tm datetime;
	time_t timestamp;
	// time(&timestamp); // chi tao timestamp cho ngay gio hien tai
	
	datetime.tm_year = 2025 - 1900;
	datetime.tm_mon = 12 - 1;
	datetime.tm_mday = 17;
	datetime.tm_hour = 12;
	datetime.tm_min = 30;
	datetime.tm_sec = 1;
	datetime.tm_isdst = -1;
	
	timestamp = mktime(&datetime); // chuyen doi struct tm => timestamp voi ngay gio bat ki
	
	cout << ctime(&timestamp);
}
