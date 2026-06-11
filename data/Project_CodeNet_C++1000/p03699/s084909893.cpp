#include <bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)(x.size()))
#define FOR(i,s,n) for (ll i = (s); (i) < (n); ++i)
#define FORD(i,s,l) for (ll i = (s); (i) >= l; --i)
#define F first
#define S second
#define TC int __tc; cin >> __tc; FOR(case_num,1,__tc+1)
#define TEST(x,i) ((x)&(1ll<<(i)))
#define SET(x,i) ((x)|(1ll<<(i)))
#define FLIP(x,i) ((x)^(1ll<<(i)))
#define CLEAR(x,i) ((x)&~(1ll<<(i)))

const double pi = 4 * atan(1);
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int MAXN = 200005;

int dp[105][105];
int n;
int num[105];

int solve(int idx, int m) {
	if (idx == n) {
		return m == 0 ? -1000000 : 0;
	}
	int &ret = dp[idx][m];
	if (ret != -1) {
		return ret;
	}
	return ret = max(solve(idx+1,m), num[idx]+solve(idx+1,(m+num[idx])%10));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(dp,-1,sizeof dp);
	cin >> n;
	FOR(i,0,n){
		cin >> num[i];
	}
	cout << max(0,solve(0,0)) << "\n";
}
