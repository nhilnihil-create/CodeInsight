#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <cstring>
using namespace std;

const int mod = 1e9 + 7;
int a, b, c, d;
int main() {
	cin >> a >> b >> c >> d;
	if (a%c == 0 && b%d == 0) { cout << "No" << endl; }
	else {
		cout << "Yes" << endl;
		for (int i = 1; i <= a; ++i) {
			for (int j = 1; j <= b; ++j) {
				if (i%c == 0 && j%d == 0) { cout << 4000 * (c*d - 1)*-1 - 1 << " "; }
				else { cout << "4000 "; }
			}
			cout << endl;
		}
	}
}