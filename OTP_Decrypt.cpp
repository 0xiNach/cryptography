#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <bitset>
using namespace std;

void main(){
	ofstream plainTextFile("plaintext.txt");
	ifstream keyFile("key.dat");
	ifstream cipherFile("ciphertext.dat");
	string plainTextString, plainTextBinaryString, keyBinaryString, cipherBinaryString, cipherTextString;
	plainTextBinaryString = "";
	keyBinaryString = "";
	cipherBinaryString = "";
	cipherTextString = "";
	if (cipherFile.is_open())
	{
		while ( getline (cipherFile,cipherTextString) )
		{
			
		}
		cipherFile.close();
	}
	
	if (keyFile.is_open())
	{
		while ( getline (keyFile,keyBinaryString) )
		{
			
		}
		keyFile.close();
	}
	else cout << "Unable to open file"; 
	for (std::size_t i = 0; i < cipherTextString.size(); ++i){
		cipherBinaryString += bitset<8>(cipherTextString.c_str()[i]).to_string();
	}

	int keyBinaryLength = keyBinaryString.length();
	int cipherLength = cipherTextString.length() * 8;
	char plainTextTempChar = '0';
	for(int i=0; i < cipherLength ; i++){
		char cipherTempChar = cipherBinaryString[i];
		char keyTempChar = keyBinaryString[i % keyBinaryLength];
		
		if(cipherTempChar == '0' && keyTempChar == '0'){
			plainTextTempChar = '0';
		}else if(cipherTempChar == '1' && keyTempChar == '1'){
			plainTextTempChar = '0';
		}else if(cipherTempChar == '1' && keyTempChar == '0'){
			plainTextTempChar = '1';
		}else if(cipherTempChar == '0' && keyTempChar == '1'){
			plainTextTempChar = '1';
		}
		plainTextBinaryString += plainTextTempChar;
	}
	stringstream sstream(plainTextBinaryString);
	while(sstream.good())
    {
        std::bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        plainTextString += c;
    }
	plainTextString = plainTextString.substr(0, plainTextString.size()-1);
	plainTextFile << plainTextString;
	plainTextFile.close();
}