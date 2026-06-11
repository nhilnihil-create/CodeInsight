#include<iostream>
#include<string>
using namespace std;

int main()
{
	

	char s[19];
	
	for (int i = 0; i < 19; i++)
		cin >> s[i];
	s[5] = ' ';
	s[13] = ' ';
	for (int j = 0; j < 19; j++)
		cout << s[j];
}