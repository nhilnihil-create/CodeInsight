#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int sum = 1;

	if (a != b) {
		sum++;
	}

	if (a != c) {
		if (b != c) {
			sum++;
		}
	}

	cout << sum << endl;
}
