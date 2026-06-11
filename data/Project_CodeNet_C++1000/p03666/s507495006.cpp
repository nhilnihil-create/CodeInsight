#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
signed main() {
	int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
	int mi = a, ma = a;
	for (int h = 1; h <= n; h++) {
		if (mi - ((n - h) * d) <= b && b <= ma - ((n - h) * c)) {
			cout << "YES" << endl; return 0;
		}
		mi += c; ma += d;
	}
	cout << "NO" << endl;
	return 0;
}