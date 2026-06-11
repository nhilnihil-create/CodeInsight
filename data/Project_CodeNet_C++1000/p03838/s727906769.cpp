#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

int main() {

	long long x, y;
	cin >> x >> y;

	long long v = abs(x) - abs(y);
	v = abs(v);

	if (y * x < 0) {
		v += 1;
	}
	else if (y * x == 0 && y - x < 0) {
		v += 1;
	}
	else if (y - x < 0) {
		v += 2;
	}

	cout << v << endl;

	return 0;
}