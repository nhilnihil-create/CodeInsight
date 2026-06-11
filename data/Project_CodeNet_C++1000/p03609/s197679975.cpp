#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int X, t;
	cin >> X >> t;
	int sand;
	if (X < t) sand = 0;
	else sand = X - t;
	cout << sand << endl;
	return 0;
}