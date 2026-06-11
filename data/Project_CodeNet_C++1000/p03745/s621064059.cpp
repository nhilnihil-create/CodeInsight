#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std; using ll = long long;
using ull = unsigned long long; using P = pair<int, int>;
const int INF = 1e9; const int MOD = 1000000007;
const int dx[] = {-1,0,1,0}; const int dy[] = {0,-1,0,1};
//const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1}; const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
#define PI 3.14159265358979323846264338327950L //setprecision(15)

int main() {
	int N; cin >> N;
	int u = 0, l = 0, back = 0;
	int ans = 0;
	rep(i, N) {
		int a; cin >> a;
		if (i == 0) {
			back = a; continue;
		}
		if (a == back) continue;
		if (u == 0 && l == 0) {
			if (a > back) u = 1;
			else l = 1;
		} else if (u == 1) {
			if (a < back) {
				ans++; u = 0; l = 0;
			}
		} else {
			if (a > back) {
				ans++; u = 0; l = 0;
			}
		}
		back = a;
	}
	ans++;
	cout << ans << endl;
}