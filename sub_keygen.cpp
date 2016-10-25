#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>


using namespace std;

int main()
{
ofstream keyfile;
keyfile.open("key.txt");

 char k[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int i,j;
char temp;
for ( i = 0; i <26; i++)
{
	j = rand()%25 + 1;
	temp = k[i];
	k[i] = k[j];
	k[j] = temp;
}

for (int i = 0; i < 26; ++i)
{
	keyfile << k[i];
}
 
  
 
 

keyfile.close();
return 0;
}


