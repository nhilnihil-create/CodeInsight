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

int arr[105];
ll dp[55][55][55*55];

int n;
int a;

ll solve(int idx, int cnt, int s){
	if (idx == n) {
		return (cnt != 0 && s%cnt==0 && s/cnt==a);
	}
	if (dp[idx][cnt][s] != -1) {
		return dp[idx][cnt][s];
	}
	return dp[idx][cnt][s] = solve(idx+1,cnt+1,s+arr[idx]) + solve(idx+1,cnt,s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> a;
	memset(dp,-1,sizeof dp);
	
	FOR(i,0,n){
		cin >> arr[i];
	}
	cout << solve(0,0,0) << "\n";
}
