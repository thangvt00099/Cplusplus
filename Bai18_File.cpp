#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream MyFile("C:\\Users\\DELL INSPIRON 5530\\Documents\\C++\\filename.txt");
	MyFile << "Noi dung 1";
	MyFile << "Noi dung 2";
	MyFile << "Noi dung 3";
	MyFile << "Noi dung 4";
	MyFile.close();
	
	string myText;
	
	ifstream MyReadFile("C:\\Users\\DELL INSPIRON 5530\\Documents\\C++\\filename.txt");
	while (getline(MyReadFile, myText)) {
		cout << myText;
	}
	MyReadFile.close();
	return 0;
}
