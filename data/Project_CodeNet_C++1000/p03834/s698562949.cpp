#include <iostream>
#include <cstdio>
using namespace std;

string a;
int main() {
	cin >> a;
	for(int i=0; a[i]; i++) {
		putchar(a[i]==',' ? ' ' : a[i]);
	}
	return 0;
}
