#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e18;
const long double PI = (acos(-1));


signed main() {
	int N, K;
	cin >> N >> K;
	vector<int>a(N);
	rep(i, N)cin >> a[i];
	int ans = INF;
	for (int i = 0; i < (1ll << N); i++) {
		if (i & 1)continue;
		vector<int>copy(N);
		copy = a;
		vector<int>v(N);
		rep(j, N)v[j] = (i >> j) & 1;
		int mx = copy[0];
		int sum = 0;
		rep(j, N) {
			if (j == 0)continue;
			if (v[j] == 1) {
				if (mx < copy[j])continue;
				sum += mx - copy[j] + 1;
				copy[j] = mx + 1;
			}
			mx = max(mx, copy[j]);
		}
		int cnt = 1;
		mx = copy[0];
		rep(j, N) {
			if (!j)continue;
			if (mx < copy[j])cnt++;
			mx = max(mx, copy[j]);
		}
		if (cnt >= K)chmin(ans, sum);
	}
	cout << ans << endl;
}