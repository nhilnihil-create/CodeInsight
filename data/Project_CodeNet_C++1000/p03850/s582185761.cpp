#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

int n;
int a[120000];
char c[120000];
const ll INF = 1e18;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		if (i != n - 1)
			scanf(" %c", c + i + 1);
	}
	c[0] = '+';
	ll mn = INF;
	ll sum = 0;
	ll cur = 0;
	ll now = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (c[i] == '+') {
			cur += a[i];
		}
		else {
			if (now != 0)
				mn = min(mn, now + cur);
			cur = 0;
			now += a[i];
		}
	}
	mn = min(mn, now);
	cout << sum - 2 * mn << "\n";
	return 0;
}


