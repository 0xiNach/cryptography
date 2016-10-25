#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;


int main()
{
char raw[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

string key;

ifstream keyfile("key.txt");
    if(keyfile.is_open())
    {
        getline(keyfile,key);
    }

keyfile.close();

string text;

char filename[50];
string file_content;
ifstream infile;

cout << "Enter the FILENAME containing plaintext: ";
cin.getline(filename,50);
infile.open(filename);

if(!infile.is_open())
{
	cout << "ERROR OPENING FILE. " <<endl;
	exit(1);
}
else
{
	while(getline(infile,text))
	{
		infile >> text;
	}
}

cout << text << endl;
	

 infile.close();

for (int i = 0; i < text.length(); ++i)
{
    text.erase(remove_if(text.begin(), text.end(), ::ispunct));

	text.erase(find(text.begin(), text.end(),' '));
	
	text.erase(remove_if(text.begin(), text.end(), ::isdigit));
    
    transform(text.begin(),text.end(),text.begin(),::tolower);
}

ofstream cipher;
cipher.open("ciphertext.txt");

 int flag;
 for (int i = 0; i < text.length();i++)
 {
 	flag=1;
 	
 	 for (int j = 0; j < 26; j++)
 	 {
 	 	
 	 	if (text[i]==raw[j] && flag==1)
 	 	{
 	 		text[i]=key[j];
 	 		flag=0;
 	 		
 	 	}
 	 }
 }
   
    cipher << text <<endl;

   cipher.close();


return 0;
}