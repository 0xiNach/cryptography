#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <bitset>
using namespace std;

int main() {
	ofstream keyFile("key.dat", ios::out);
	string binaryString = "";
	for (int j = 0; j < 102400 / 8; j++) {
		
		int asciiValue = 48 + rand() % (57 - 48 + 1);
		int m[8], i;
		char asciiChar = asciiValue;
		
		for (int i = 7; i >= 0; --i) {
			binaryString = binaryString +  ((asciiChar & (1 << i)) ? '1' : '0');
		}
		
	}
	keyFile << binaryString;
	keyFile.close();
}