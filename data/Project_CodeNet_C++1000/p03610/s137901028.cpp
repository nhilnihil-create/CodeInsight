#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char s[100000];
	cin >> s;
	for(int i=0; i<strlen(s); i+=2){
			cout << s[i];
	}
	cout << endl;
}