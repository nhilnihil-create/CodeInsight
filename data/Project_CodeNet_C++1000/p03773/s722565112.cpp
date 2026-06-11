#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (a + b >= 24)
		cout << a + b - 24 << "\n";
	else
		cout << a + b << "\n";
}