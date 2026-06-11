#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

const int mn = 300;
bool isp[mn+1];
void init() {
	fill(isp + 2, isp + mn+1, true);
	Rep1(i, 2, mn) {
		if (!isp[i])continue;
		for (int j = 2 * i; j <= mn; j += i) {
			isp[j] = false;
		}
	}
}
bool testmincase(int n,int m) {
	if (isp[n])return false;
	vector<bool> used(n, false);
	queue<int> q; q.push(0); used[0] = true;
	rep(i, n) {
		if (isp[i + 1])used[i] = true;
	}
	while (!q.empty()) {
		int id = q.front(); q.pop();
		if (id%m) {
			if (!used[id - 1]) {
				used[id - 1] = true; q.push(id - 1);
			}
		}
		if ((id%m) < m - 1 && id < n - 1) {
			if (!used[id + 1]) {
				used[id + 1] = true; q.push(id + 1);
			}
		}
		if (id - m >= 0) {
			if (!used[id - m]) {
				used[id - m] = true; q.push(id - m);
			}
		}
		if (id + m < n) {
			if (!used[id + m]) {
				used[id + m] = true; q.push(id + m);
			}
		}
	}
	return used[n - 1];
}
int a[1 << 18]; int n;
bool can(int x) {
	vector<int> b(2 * n - 1);
	rep(i, 2 * n - 1) {
		if (a[i] < x)b[i] = 0;
		else b[i] = 1;
	}
	int le = 0, ri = 2 * n - 2;
	for (int i = n - 1; i > 0; i--) {
		if (b[i] == b[i - 1]) {
			le = i; break;
		}
	}
	for (int i = n - 1; i < 2 * n - 2; i++) {
		if (b[i] == b[i + 1]) {
			ri = i; break;
		}
	}
	if (b[le] == b[ri])return b[le];
	if (n - 1 - le < ri - (n - 1))return b[le];
	else return b[ri];
}
void solve() {
	
	cin >> n;
	rep(i, 2 * n - 1)cin >> a[i];
	int le = 0, ri = 2 * n;
	while (ri - le > 1) {
		int mid = (ri + le) / 2;
		if (can(mid))le = mid;
		else ri = mid;
	}
	cout << le << endl;
}
int main() {
	solve();
	//stop
	return 0;
}
