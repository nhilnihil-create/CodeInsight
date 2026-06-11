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
const ll mod = (1e+9) + 7;
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
const ld eps = 1e-4;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
ll dp[1 << 20];
int main() {
	ll sum = 0;
	int n; cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	dp[0] = 1;
	ll out = 0;
	rep(i, n-1) {
		dp[i] += sum; dp[i] %= mod;
		if (i > 1) {
			dp[i] -= dp[i - 2]; dp[i] = (dp[i] + mod) % mod;
		}
		out = (out + dp[i] * (n - 1) % mod*(n - 1) % mod)%mod;
		out = (out + (n+1-max(2,n-i-1))*dp[i]%mod)%mod;
		sum += dp[i]; sum %= mod;
	}
	if (n > 2) {
		sum -= dp[n - 3]; sum = (sum + mod) % mod;
	}
	cout << (out + sum*n) % mod << endl;
	return 0;
}
