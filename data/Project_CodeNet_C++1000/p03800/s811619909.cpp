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

//
int main() {
	int N; cin >> N;
	string s; cin >> s;
	int ans[100100];//1が羊
	for (int i = 0; i < 2; ++i) {
		//ans[0]が羊か狼か
		for (int j = 0; j < 2; ++j) {
		//ans[1]が羊か狼か
			ans[0] = i;
			ans[1] = j;
			for (int k = 2; k < N; ++k) {
				if (ans[k-1] == 1) {
					if (s[k-1]=='o') {
						ans[k] = ans[k-2];
					}
					else {
						ans[k] = 1 - ans[k-2];
					}
				}
				else {
					if (s[k-1]=='o') {
						ans[k] = 1 - ans[k-2];
					}
					else {
						ans[k] = ans[k - 2];
					}
				}
			}
			if (s[0]=='o') {
				if (ans[0] == 1) {
					if (ans[N - 1] != ans[1])continue;
				}
				else {
					if (ans[N - 1] == ans[1])continue;
				}
			}
			else {
				if (ans[0] == 1) {
					if (ans[1] == ans[N - 1])continue;
				}
				else {
					if (ans[1] != ans[N - 1])continue;
				}
			}
			if (s[N - 1] == 'o') {
				if (ans[N - 1] == 1) {
					if (ans[0] != ans[N - 2])continue;
				}
				else {
					if (ans[0] == ans[N - 2])continue;
				}
			}
			else {
				if (ans[N - 1] == 1) {
					if (ans[0] == ans[N - 2])continue;
				}
				else {
					if (ans[0] != ans[N - 2])continue;
				}
			}
			REP(i, N) {
				if (ans[i] == 1)cout << 'S';
				else cout << 'W';
			}
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}