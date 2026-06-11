#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int x, a, b;
	cin >> x >> a >> b;
	if (abs(x - a) > abs(x - b))
		cout << "B" << "\n";
	else
		cout << "A" << "\n";
}