#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define fu(a,b,c) for(int a=b;a<=(int)c;++a)
#define fd(a,b,c) for(int a=b;a>=(int)c;--a)
#define cu(a,b,c) for(int a=b;a<(int)c;++a)
#define cd(a,b,c) for(int a=(b)-1;a>=(int)c;--a)
#define gcd(a,b) __gcd(a,b) 
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define pf push_front
#define uint unsigned int
#define MOD 100000007
#define MAXN 200005
#define MAXH 4
#define MAXM 100
#define ll long long
#define ull unsigned long long
#define RNG rng mt19937(time(NULL))
#define udist(a,b) uniform_int_distribution<uint32_t> distribution(a,b)
#define max3(a,b,c) max(a, max(b, c))
#define min3(a,b,c) min(a, min(b, c))
#define gmax(a,b) a = max(a, b)
#define gmin(a,b) a = min(a, b)
#define whatis(x) cerr << #x << " is " << x << endl;
#define T long long
#define mat vector<vector<T>>
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define cld complex<long double>
using namespace std;

int main(){
	fast_io();
	string s;
	cin >> s;
	int n = s.length();
	vector<vector<int>> dp(n, vector<int>(26));
	cu(i,0,26)dp[n-1][i] = 0;
	dp[n-1][s[n-1]-'a'] = 1;
	cd(i,n-1,0){
		int mn = MOD;	
		cu(j,0,26)gmin(mn, dp[i+1][j]);
		cu(j,0,26)dp[i][j] = dp[i+1][j];
		dp[i][s[i] - 'a'] = mn + 1;
	}
	string ans = "";
	int cur = 0;
	while(cur < n){
		int best = MOD, bestind = -1;
		cu(i,0,26){
			if(dp[cur][i] < best){
				bestind = i;
				best = dp[cur][i];
			}
		}
		ans+=bestind + 'a';
		while(cur < n && s[cur] - 'a' != bestind){
			++cur;
		}
		if(s[cur] - 'a' == bestind){++cur;}
	}
	cout << ans << '\n';
}
