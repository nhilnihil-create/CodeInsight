//	ZapZu's code hohoho
//	#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
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

#define iii pr<int, ii> 
mii fp, cnt, ans; 
signed main()
{
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);
	int n;
	cin>>n;
	for(int i=1, t; i<=n; i++)
	{
		cin>>t;
		if(!fp.count(t)) fp[t] = i;
		cnt[t]++;
	}
	vt<iii> A(1);
	for(auto tmp: cnt)
	{
		int t = tmp.fi;
		A.pb({t, {fp[t], cnt[t]}});
//		cout<<t<<" "<<fp[t]<<" "<<cnt[t]<<endl;
	}
	int lastid = n+1;
	for(int i=A.size()-1; i>=1; i--)
	{
//		cout<<A[i].fi<<" "<<A[i].se.fi<<" "<<A[i].se.se<<endl;
		lastid = min(lastid, A[i].se.fi);
		ans[lastid]+=(A[i].fi-A[i-1].fi)*A[i].se.se;
		A[i-1].se.se+=A[i].se.se;
	}
	for(int i=1; i<=n; i++)
	{
		cout<<ans[i]<<endl;
	}
}


