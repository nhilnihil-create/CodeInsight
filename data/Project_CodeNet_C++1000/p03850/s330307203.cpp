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
const ll inf = (1LL << 60);

int n;
ll p[MAXN], p1[MAXN], dp[MAXN][4];

ll rek(int a, int t) {
	if (a == n) return 0;
	if (t == 4) return -(1LL << 54);
	if (dp[a][t] != -1) return dp[a][t];

	ll ret = -inf;
	
	if (t) ret = max(ret, rek(a, t - 1));
	int b = t % 2;
	
	if (!(b ^ p1[a])) ret = max(ret, rek(a + 1, t) + p[a]);
	else ret = max(ret, rek(a + 1, t) - p[a]);
	
	if (p1[a]) {
		int B = !b;
		if (!B) ret = max(ret, rek(a + 1, t + 1) + p[a]);
		if (B) ret = max(ret, rek(a + 1, t + 1) - p[a]);
	}

	return dp[a][t] = ret;
}

int main() {
	scanf("%d",&n);
	scanf("%lld",&p[0]);
	REP(i, n - 1) {
		char s[2];
		scanf("%s %lld",s,&p[i + 1]);
		if (s[0] == '-') p1[i + 1] = 1;
	}

	memset(dp, -1, sizeof dp);
	printf("%lld\n",rek(0, 0));
	return 0;
}
