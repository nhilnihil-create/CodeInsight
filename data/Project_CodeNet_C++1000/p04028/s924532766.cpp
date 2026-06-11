#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = (ll)(1e+9) + 7;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
ll dp[5001][5002];
void init() {
	dp[0][0] = 1;
	rep1(i, 5000) {
		dp[i][0] = (dp[i - 1][0] + 2*dp[i - 1][1]) % mod;
		rep1(j, i) {
			dp[i][j]=(dp[i-1][j-1]+2*dp[i-1][j+1])%mod;
		}
	}
}
int main() {
	init();
	int n; cin >> n;
	string s; cin >> s;
	int m = s.length();
	cout << dp[n][m] << endl;
	return 0;
}