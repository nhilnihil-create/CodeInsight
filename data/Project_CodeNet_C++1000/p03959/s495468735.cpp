#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define INF 10000000000000007
#define ggr getchar(); getchar();return 0;
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}

int n, t[100010], a[100010];

signed main() {
	cin >> n;
	rep(i, n)cin >> t[i];
	rep(i, n)cin >> a[i];
	if (t[n - 1] != a[0]) {
		cout << 0 << endl;
		ggr

	}
	long long ta = 1;
	for (int i = 1; i < n - 1; i++) {
		if (t[i - 1]<t[i] && a[i]>a[i*+1] && t[i] != a[i]) {
			cout << 0 << endl;
			ggr
		}
		if ((t[i - 1]<t[i] && t[i]>a[i]) || (a[i] > a[i + 1] && a[i] > t[i])) {
			cout << 0 << endl;
			ggr
		}
		if (t[i - 1] == t[i] && a[i] == a[i + 1]) {
			ta *= min(t[i], a[i]);
			ta %= mod;
		}
	}
	cout << ta << endl;
	ggr
}
