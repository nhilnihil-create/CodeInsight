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
const ll dx[4] = { 0, -1, 1, 0 };
const ll dy[4] = { -1, 0, 0, 1 };
const ll INF = 1e9 + 7;
const ll inf = 1LL << 50;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
///////////////////////////////////////
ll T[100100], A[100100];
ll ans[100100];
int main() {
	ll N; cin >> N;
	bool ok = true;
	REP(i, N)cin >> T[i];
	REP(i, N)cin >> A[i];
	for (int i = 0; i < N; ++i) {
		ans[i] = min(T[i], A[i]);
	}
	ans[0] = 1;
	ans[N - 1] = 1;
	for (int i = 0; i < N - 1; ++i) {
		if (T[i] != T[i + 1]) {
			ans[i + 1] = 1;
		}
	}
	for (int i = N - 1; i >= 1; --i) {
		if (A[i] != A[i - 1]) {
			ans[i-1] = 1;
		}
	}
	ll res = 1;
	for (int i = 0; i < N; ++i) {
		res *= ans[i];
		res %= INF;
	}
	if (A[0] != T[N-1]) {
		ok = false;
	}
	for (int i = 0; i < N - 1; ++i) {
		if (T[i] != T[i + 1] ) {
			if (T[i+1] > A[i+1]) {
				ok = false;
			}
		}
	}
	for (int i = N - 1; i >= 1; --i) {
		if (A[i] != A[i - 1]) {
			if (A[i - 1] > T[i - 1]) {
				ok = false;
			}
		}
	}
	if (ok) {
		cout << res << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}