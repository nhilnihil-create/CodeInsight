#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (c >= b && c >= a)
		cout << a + b << "\n";
	else if (a >= b && a >= c)
		cout << b + c << "\n";
	else
		cout << a + c << "\n";
}