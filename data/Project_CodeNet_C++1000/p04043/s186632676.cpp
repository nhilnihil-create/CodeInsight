#include<iostream>

using namespace std;

int main() {
	int five, seven, a, b, c;
	five = seven = 0;
	cin >> a >> b >> c;
	if (a == 5) {
		five++;
	}
	else if (a == 7) {
		seven++;
	}
	if (b == 5) {
		five++;
	}
	else if (b == 7) {
		seven++;
	}
	if (c == 5) {
		five++;
	}
	else if (c == 7) {
		seven++;
	}
	if (five == 2 && seven == 1) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}