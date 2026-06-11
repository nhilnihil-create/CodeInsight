#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bitset>
#include <cmath>
#include <set>

#define rep(i,s,n)for(int i = s;i<n;i++)
#define repe(i,s,n)for(int i = s;i<=n;i++)
#define rep_r(i,s,n)for(int i = n-1;i>=s;i--)
#define rep_re(i,s,n)for(int i = n;i>=s;i--)
using namespace std;
typedef long long ll;
static const ll MOD = 1e9 + 7;
static const ll INF = 1e25;
static const ll MAX_M = 100001;

ll a[200001] = {};
ll b[200001] = {};
ll p[200001] = {};
int main() {
	ll n; cin >> n;
	repe(i, 1, n)cin >> p[i];

	repe(i, 1, n) {
		ll s = 30000;
		a[i] = i * s;
		b[i] = (n - i + 1) * s;
	}
	repe(i, 1, n) {
		a[p[i]] += i;
		//if (i < n / 2) {
		//	a[p[i]] -= n - i;
		//}
		//else {
		//	a[p[i]] += i;
		//}
	}

	//ans
	repe(i, 1, n) {
		cout << a[i];
		if (i != n) cout << " ";
	}
	cout << endl;
	repe(i, 1, n) {
		cout << b[i];
		if (i != n) cout << " ";
	}
	cout << endl;

	return 0;
}
