#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int x, t;
	cin >> x >> t;
	if (x <= t)
		cout << "0" << "\n";
	else
		cout << x - t << "\n";
}