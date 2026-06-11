#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007
#define INIT -1

int main() {
	long long int a[7];
	for (int i = 0; i < 7; i++) {
		cin >> a[i];
	}
	long long int k = 0;
	k += 2 * (a[0] / 2);
	k += a[1];
	k += 2 * (a[3] / 2);
	k += 2 * (a[4] / 2);
	if (a[0] > 0 && a[3] > 0 && a[4] > 0) {
		long long int tmpk = 0;
		tmpk += 3;
		a[0]--;
		a[3]--;
		a[4]--;
		tmpk += 2 * (a[0] / 2);
		tmpk += a[1];
		tmpk += 2 * (a[3] / 2);
		tmpk += 2 * (a[4] / 2);
		k = max(k, tmpk);
	}

	cout << k << endl;
}