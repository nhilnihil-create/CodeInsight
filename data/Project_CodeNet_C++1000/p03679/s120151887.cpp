#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int x, a, b;
	cin >> x >> a >> b;
	if (a >= b)
		cout << "delicious" << "\n";
	else if (b - a <= x)
		cout << "safe" << "\n";
	else
		cout << "dangerous" << "\n";
}