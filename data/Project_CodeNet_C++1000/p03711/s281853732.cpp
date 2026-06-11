#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	if (x == 2 || x == 11 || y == 2 || y == 4) {
		cout << " No" << "\n";
	}
	else if (x == 4 || x == 6 || x == 9) {
		if (y == 6 || y == 9 || y == 11)
			cout << "Yes" << "\n";
		else
			cout << "No" << "\n";
	} else {
		if (y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12)
			cout << "Yes" << "\n";
		else
			cout << "No" << "\n";
	}
}