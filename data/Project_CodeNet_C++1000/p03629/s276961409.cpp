#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<fstream>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

const int MAX = 1010000;
const int MOD = (ll)1000000000 + 7;
const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;

//typedef pair<int, int> P;

int dp[202020];
int nex[202020][27];
map<char, int>mp;
signed main() {
	REP(i, 26) {
		mp['a' + i] = i;
	}
	string S; cin >> S;
	m0(dp);
	int N = S.size();
	REP(i, 26) {
		nex[N][i] = N + 1;
	}

	for (int i = N-1; i>=0;i--) {
		REP(j, 26) {
			nex[i][j] = nex[i + 1][j];
		}
		nex[i][mp[S[i]]] = i + 1;
	}
	//print(N); REP(i, N)print(nex[0][i]);
	dp[N] = 1;
	for (int i = N - 1; i >= 0; i--) {
		int mn = INF;
		REP(j, 26) {
			mn = min(mn, dp[nex[i][j]]);
		}
		dp[i] = mn + 1;
	}

	int M = dp[0];
	string ans;
	int pos = 0;
	while (M > 0) {
		REP(j, 26) {
			if (dp[nex[pos][j]] == M - 1) {
				ans += 'a' + j;
				pos = nex[pos][j];
				M--;
				break;
			}
		}
	}
	print(ans);
}
