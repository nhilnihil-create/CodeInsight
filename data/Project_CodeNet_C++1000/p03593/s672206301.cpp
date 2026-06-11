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
#include <queue>
#include <stack>

typedef long long ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)
#define repe(i,s,n)for(ll i = s;i<=n;i++)
#define rep_r(i,s,n)for(ll i = n;i>s;i--)
#define rep_re(i,s,n)for(ll i = n;i>=s;i--)
using namespace std;
static const ll MOD = 1e9 + 7;
static const ll INF = 1e25;
static const ll MAX_N = 100001;
ll a[101][101];
ll c[26];
int main() {
	ll h, w; cin >> h >> w;
	rep(i, 0, h)rep(j, 0, w) {
		char x; cin >> x;
		a[i][j] = x;
		c[x - 'a']++;
	}
	ll p[4] = {};
	rep(i, 0, 26) {
		p[c[i] % 4]++;
	}

	if (!(h & 1) && !(w & 1)) {
		cout << ((p[1] == 0 && p[3] == 0 && p[2] == 0) ? "Yes" : "No") << endl;
		return 0;
	}
	else if (!(h & 1) || !(w & 1)) {
		if (!(h & 1))swap(h, w);

		if (p[1] == 0 && p[3] == 0 && p[2] <= w / 2) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
		return 0;
	}
	else {
		if (p[1] == 1 && p[3] == 0 && p[2] <= (h - 1) / 2 + (w - 1) / 2) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
		return 0;
	}
	return 0;
}