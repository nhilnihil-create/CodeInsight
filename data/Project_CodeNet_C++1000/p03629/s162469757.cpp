//	ZapZu's code hohoho
//	#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define dfs_black 1
#define dfs_white -1
#define pr pair
#define vt vector
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long li;
typedef long double ld;

typedef pr<int, int> ii;
typedef pr<ld,ld> dd;

typedef vt<int> vi;
typedef vt<li> vli;
typedef vt<ld> vld;
typedef vt<ii> vii;

typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, char> mic;

typedef set<int> s_i;
typedef set<char> s_c;

const int MOD = 1e9+7;
const li INF = 1e18;
const ld PI = 4*atan((ld)1);
int nxt[200005][26];
int dp[200005], trc[200005];
vi ans;
signed main()
{
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);
	string s; cin>>s; int n = s.length();
	s = '$'+s;
	fill(dp, dp+n+3, INT_MAX/10);
	for(int i=n+1; i>=0; i--)
	{
		for(int j=0; j<26; j++)
		{
			if(i==n+1) nxt[i][j] = i;
			else if(s[i+1]-'a'==j) nxt[i][j] = i+1;
			else nxt[i][j] = nxt[i+1][j];
		}
	}
	for(int i=n+1; i>=0; i--)
	{
		if(i==n+1) dp[i]=1;
		else
		for(int j=0; j<26; j++)
		{
			if(dp[i]>dp[nxt[i][j]]+1) 
			{
				dp[i]=dp[nxt[i][j]]+1;
				trc[i]=j;
			}
		}
	}
	int cur=0;
	while(cur<n+1)
	{
		int temp = trc[cur];
		ans.eb(temp);
		cur = nxt[cur][temp];
	}
	for(auto c: ans) cout<<char(c+'a');
}


