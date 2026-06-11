#include <iostream>
#include <cstdio>
using namespace std;

int c;
string s, t="CODEFESTIVAL2016";
int main() {
	cin >> s;
	for(int i=0; s[i]; i++) if(s[i] != t[i]) c++;
	cout << c;
	return 0;
}
