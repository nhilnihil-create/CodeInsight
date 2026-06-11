#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b && a == c)
		cout << a + b << "\n";
	else if (a + b < a + c && a + b < b + c)
		cout << a + b << "\n";
	else if (a + c < b + c)
		cout << a + c << "\n";
	else
		cout << b + c << "\n";
}