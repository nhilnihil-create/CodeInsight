#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647

int main() {
	long long x;
	cin >> x;

	long long count = 2 * ((x - x % 11) / 11);
	if (0 < x % 11 && x % 11 < 7) {
		count += 1;
	}
	else if(6 < x % 11){
		count += 2;
	}
	

	cout << count << endl;

	return 0;
}