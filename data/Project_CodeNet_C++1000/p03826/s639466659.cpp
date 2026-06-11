#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a * b < c * d)
		cout << c * d << "\n";
	else
		cout << a * b << "\n";
}