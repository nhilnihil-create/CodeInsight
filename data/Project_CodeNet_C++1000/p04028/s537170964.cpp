#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define allV(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair< int, int > pii;
typedef pair< LL, LL > pLL;
typedef vector< pLL > vpLL;
typedef vector< int > vi;
typedef vector< pii > vpii;
typedef vector< LL > vL;

// GLOBAL
const int inf = 1e9+3;
const LL linf = (LL)inf*inf+2;

const LL MOD = 1e9+7;

int N;
LL S, dp[5002][5002];
// --

LL foo(int steps, int wordLen) {
	if (wordLen > steps) return 0;
	if (wordLen < 0) return 0;
	if (steps == 0) {
		if (wordLen == 0) return 1;
		return 0;
	}
	LL &DP = dp[steps][wordLen];
	if (DP == -1)
		DP = (foo(steps-1, max(0, wordLen-1)) + (foo(steps-1, wordLen+1)*2) % MOD) % MOD;
	// cout << steps << ' ' << wordLen << " -> " << DP << endl;
	return DP;
}

int main()
{
	ios_base::sync_with_stdio(false);

	memset(dp, -1, sizeof(dp));
	string str;
	cin >> N >> str;
	S = str.length();

	cout << foo(N, S) << '\n';

	return 0;
}
