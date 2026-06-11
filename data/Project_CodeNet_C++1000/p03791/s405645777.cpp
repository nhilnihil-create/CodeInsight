#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef double lf;
typedef long double Lf;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;

#define TRACE(x) cerr << #x << "  " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define _ << " " <<

#define fi first
#define sec second
#define mp make_pair

const int MAXN = 100100;
const int MOD = 1e9+7;

int mul(int a, int b) {
	return (ll)a * b % MOD;
}

int n, p[MAXN], dp[MAXN], cnt[MAXN];

set <pii> s;
map <int, int> mapa;

int main() {
	scanf("%d",&n);
	REP(i, n) scanf("%d",&p[i]);
	s.insert(mp(-1, 0));
	REP(i, n) {
		pii t = *s.rbegin();
		dp[i] = t.sec;
		if (mapa[t.fi - 1]) {
			mapa[t.fi]--;
			s.erase(--s.end());
			dp[i]++;
			t = *s.rbegin();
		}
		s.insert(mp(min(p[i], t.fi + 2), dp[i]));
		mapa[min(p[i], t.fi + 2)]++;
		cnt[dp[i]]++;
	}

	int uk = 0, sol = 1;
	REP(i, n) {
		uk += cnt[i];
		sol = mul(sol, uk - i);
		int t = uk-i;
	}
	printf("%d\n",sol);
	return 0;
}