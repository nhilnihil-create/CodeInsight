#include <iomanip>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
int main() {
	long long int n, a, b;
	cin >> n;
	for (int i = 1; i >= 0; i++) {
		a = i*(i + 1) / 2;
		if (n <= a) {
			b = i;
			break;
		}
	}
	a -= n;
	for (int i = 1; i <= b; i++) {
		if (i != a) {
			cout << i << endl;
		}
	}
	return 0;
}