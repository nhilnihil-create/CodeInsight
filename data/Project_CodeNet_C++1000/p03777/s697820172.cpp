#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	char a, b;
	cin >> a >> b;
	if (a == 'H')
		if (b == 'H')
			cout << "H" << "\n";
		else
			cout << "D" << "\n";
	else
		if (b == 'H')
			cout << "D" << "\n";
		else
			cout << "H" << "\n";
}