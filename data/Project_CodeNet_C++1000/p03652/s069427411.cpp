#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };
const int INF = 1e9 + 7;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}

template<class T1, class T2> void chmin(T1 &a, T2 b) { if (a>b)a = b; }

template<class T1, class T2> void chmax(T1 &a, T2 b) { if (a<b)a = b; }
template<class T>
void Add(T &a, const T &b, const T &mod = 1000000007) {
	int val = ((a % mod) + (b % mod)) % mod;
	if (val < 0) { val += mod; }
	a = val;
}
////////////////////////////////////////
bool used[310];
int n, m;
int a[310][310];
int cnt[310];
int dfs() {
	REP(i, 310)cnt[i] = 0;
	REP(i, n) {
		REP(j,m) {
			if (used[a[i][j]])continue;
			else{
				cnt[a[i][j]]++;
				break;
			}
		}
	}
	int id = 305;
	int max = 0;
	REP(i,m) {
		if (max < cnt[i]) {
			max = cnt[i];
			id = i;
		}
	}
	used[id] = true;
	return max;
}
int main() {
	REP(i, 310) {
		cnt[i] = 0;
		used[i] = false;
	}
	cin >> n >> m;
	REP(i, n) {
		REP(j, m) {
			cin >> a[i][j];
			a[i][j]--;
		}
	}
	int ans = INF;
	for (int i = 0; i < m ; ++i) {
		ans = min(ans, dfs());
	}
	cout << ans << endl;
	return 0;
}