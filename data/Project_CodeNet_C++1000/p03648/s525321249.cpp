#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <set>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstring>

using namespace std;
using ll = long long;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<string, string> sP;
typedef pair<ll, pair<ll, ll>> PP;

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1 << 30;
const ll INF2 = 9e18;
const double INF3 = 9e14;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second



int main() {
	ll K;
	cin >> K;
	vector<ll>v[51], sa[51][51];
	for (int i = 2;i <= 50;i++) {
		for (int j = 1;j <= i;j++) {
			v[i].eb(100);
			sa[i][0].eb(0);
		}

		for (int j = 1;j <= i;j++) {
			int maxit = -1, ma = 0;
			for (int k = 0;k < i;k++) {
				if (ma < v[i][k])ma = v[i][k], maxit = k;
			}
			for (int k = 0;k <= i;k++) {
				if (k == maxit) {
					sa[i][j].eb(v[i][k] - i - 100);
					v[i][k] -= i;
				}
				else {
					sa[i][j].eb(v[i][k] + 1 - 100);
					v[i][k]++;
				}
			}
		}
	}

	

	for (ll i = 2;i <= 50;i++) {
		ll l = K / i, r = K / i + 1, mod = K % i;
		if (l + (i - 1) > (ll)1e16 + 100LL)continue;
		if (mod == 0) {
			cout << i << endl;
			for (int j = 0;j < i;j++) {
				cout << l + i-1 << ' ';
			}
			cout << endl;
			return 0;
		}
		ll x = r+i-1;
		//cout << x << endl;
		cout << i << endl;
		for (int j = 0;j < i;j++) {
			cout << x + sa[i][i-mod][j] << ' ';
		}
		cout << endl;
		return 0;
	}
	return 0;
}