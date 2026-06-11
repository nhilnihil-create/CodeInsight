#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void agc_a_divide_a_cuboid(void) {
	long long a, b, c;
	cin >> a >> b >> c;
	// 底面の決め方で3通り
	long long min_diff = a * b;

	long long s = 0;

	if ((a % 2 == 0) || (b % 2 == 0) || (c % 2 == 0)) {
		cout << "0" << endl;
		return;
	}

	s = b * c;
	if (s< min_diff) min_diff = s;

	s = a * c;
	if (s < min_diff) min_diff = s;

	cout << min_diff << endl;
}

int main()
{
    agc_a_divide_a_cuboid();
    return 0;
}