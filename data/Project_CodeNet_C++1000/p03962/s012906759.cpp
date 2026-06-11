#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int count;
	if (a == b) {
		if (b == c) count = 1;
		else count = 2;
	}
	else if (b == c) count = 2;
	else if (a == c) count = 2;
	else count = 3;
	cout << count << endl;
	return 0;
}