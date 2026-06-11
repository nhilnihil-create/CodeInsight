#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	if (x == 2 || y == 2 || x == 11 || y == 4)
		cout << "No" << "\n";
	else if (x == 4 || x == 6 || x == 9) {
		if (y == 6 || y == 9 || y == 11)
			cout << "Yes" << "\n";
		else
			cout << "No" << "\n";
	}
	else {
		if (y == 6 || y == 9 || y == 11)
			cout << "No" << "\n";
		else
			cout << "Yes" << "\n";
	}
}