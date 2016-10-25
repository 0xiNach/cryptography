#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <bitset>
using namespace std;

int main(){
	ifstream plainTextFile("input.txt");
	ifstream keyFile("key.dat");
	ofstream cipherFile("ciphertext.dat", ios::out, ios::binary);
	string plainTextString, plainTextBinaryString, keyBinaryString, cipherBinaryString, cipherTextString;
	plainTextBinaryString = "";
	keyBinaryString = "";
	cipherBinaryString = "";
	cipherTextString = "";
	if (plainTextFile.is_open())
	{
		while ( getline (plainTextFile,plainTextString) )
		{
			
		}
		plainTextFile.close();
	}
	
	if (keyFile.is_open())
	{
		while ( getline (keyFile,keyBinaryString) )
		{
			
		}
		keyFile.close();
	}
	else cout << "Unable to open file"; 
	for (std::size_t i = 0; i < plainTextString.size(); ++i){
		plainTextBinaryString += bitset<8>(plainTextString.c_str()[i]).to_string();
	}

	
	int keyBinaryLength = keyBinaryString.length();
	int plainTextLength = plainTextString.length() * 8;
	char cipherTempChar = '0';
	for(int i=0; i < plainTextLength ; i++){
		char plainTextTempChar = plainTextBinaryString[i];
		char keyTempChar = keyBinaryString[i % keyBinaryLength];
		
		if(plainTextTempChar == '0' && keyTempChar == '0'){
			cipherTempChar = '0';
		}else if(plainTextTempChar == '1' && keyTempChar == '1'){
			cipherTempChar = '0';
		}else if(plainTextTempChar == '0' && keyTempChar == '1'){
			cipherTempChar = '1';
		}else if(plainTextTempChar == '1' && keyTempChar == '0'){
			cipherTempChar = '1';
		}
		cipherBinaryString += cipherTempChar;
	}
	stringstream sstream(cipherBinaryString);
	while(sstream.good())
    {
        std::bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        cipherTextString += c;
    }
	cipherTextString = cipherTextString.substr(0, cipherTextString.length()-1);
	cipherFile << cipherTextString;
	cipherFile.close();
}