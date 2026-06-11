#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define INF INT_MAX/3
#define ALL(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define ll long long
#define ull unsigned long long

#define PI (3.1415926535897932)
#define eps 1e-8

void solve(ll N) {
	int cnt = -2; int fwd[101] = {};

	for (ll i = N; i > 0; i >>= 1) {
		cnt++;
		if (i & 1) {
			cnt++;
			fwd[cnt] = 1;
		}
	}

	cout << cnt + 100 << endl;
	FOR(i, 1, 101)cout << i << " ";
	RFOR(i, 0, cnt) {
		if (fwd[cnt - i - 1] == 1)cout << i + 1 << " ";
	}
	FOR(i, 0, cnt) {
		if (fwd[cnt - i - 1] == 0)cout << i + 1 << " ";
	}
	cout << endl;
}

int main() {
	ll N;
	cin >> N;
	solve(N + 1);
}