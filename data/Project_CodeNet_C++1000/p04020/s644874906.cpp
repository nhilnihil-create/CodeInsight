#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
long long a[100010];
int main() {
	int n;
	cin >> n;
	long long co = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		co += a[i] / 2;
	}
	bool b = false;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			b = false;
		}
		if (b == true && a[i] % 2 != 0) {
			co++;
			b = false;
		}
		else if (a[i] % 2 != 0) {
			b = true;
		}
	}
	cout << co << endl;
	return 0;
}
