#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#define _USE_MATH_DEFINES
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
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0,1,0,-1 };
const ll dy[4] = { -1, 0, 1,0 };
const ll INF = 1e9 + 7;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
double mysqrt(double x) {
	double l = 0, r = x;
	for (int i = 0; i < 64; ++i) {
		double m = (l + r) / 2.0;
		if (m*m < x)l = m;
		else r = m;
	}
	return l;
}
///////////////////////////////////////


int main() {
	int N, x; cin >> N >> x;
	if (x == 1 || x == 2 * N - 1) {
		cout << "No" << endl;
		return 0;
	}
	int ans[200000];
	if (x != 2) {
		ans[N - 2] = x - 1;
		ans[N - 1] = x;
		ans[N] = x + 1;
		queue<int>que;
		for (int i = 1; i < 2 * N; ++i) {
			if (i != x-1 && i != x && i != x+1) {
				que.push(i);
			}
		}
		REP(i, 2 * N - 1) {
			if (i == N - 2 ||i== N - 1 || i==N)continue;
			ans[i] = que.front();
			que.pop();
		}
	}
	else {
		ans[N - 2] = 3;
		ans[N - 1] = 2;
		ans[N] = 1;
		queue<int>que;
		for (int i = 1; i < 2 * N; ++i) {
			if (i != 3 && i != 2 && i != 1) {
				que.push(i);
			}
		}
		REP(i, 2 * N - 1) {
			if (i == N - 2 || i==N - 1 || i==N)continue;
			int x = que.front();
			ans[i] = x;
			que.pop();
		}
	}
	cout << "Yes" << endl;
	REP(i, 2 * N-1) {
		cout << ans[i] << endl;
	}
	return 0;
}