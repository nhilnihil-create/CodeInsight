#include<iostream>
#include<string>
using namespace std;
int main() {
	int a, c, d;
	string b;
	cin >> a;
	cin >> b;
	cin >> c;
	if (b == "+") {
		d = a + c;
		cout << d;
	}
	else if (b == "-") {
		d= a - c;
		cout << d;
	}



}
	