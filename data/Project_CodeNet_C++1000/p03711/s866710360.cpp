#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	string ans = "Yes";
	if (x == 2 || y == 2) ans = "No";
	else if (x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12) {
		if (y == 4 || y == 6 || y == 9 || y == 11) ans = "No";
	}
	else if (x == 4 || x == 6 || x == 9 || x == 11) {
		if (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12) ans = "No";
	}
	cout << ans << endl;
	return 0;
}