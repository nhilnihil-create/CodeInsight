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
#include <tuple>
#include<map>

using namespace std;
int main() {
	int a, b, c;

	cin >> a >> b >> c;

	bool ans = false;

	if (a + b == c) ans = true;
	else if (a + c == b) ans = true;
	else if (b + c == a) ans = true;

	if (ans) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	
}