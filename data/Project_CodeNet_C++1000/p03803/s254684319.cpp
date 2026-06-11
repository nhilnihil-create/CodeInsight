#include <iostream>
#include <cstdio>
using namespace std;

int a, b;
int main() {
	cin >> a >> b;
	if(a==1) a = 14;
	if(b==1) b = 14;
	if(a>b) puts("Alice");
	else if(a<b) puts("Bob");
	else puts("Draw");
	return 0;
}
