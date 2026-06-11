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
int pf1[200005], pf2[200005];
signed main()
{
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);
	string s, t;
	cin>>s>>t;
	for(int i=0; i<s.length(); i++) pf1[i+1] = pf1[i]+(s[i]=='A'? 1: -1);
	for(int i=0; i<t.length(); i++) pf2[i+1] = pf2[i]+(t[i]=='A'? 1: -1);
	int q;
	cin>>q;
	while(q--)
	{
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		int t1 = pf1[b] - pf1[a-1], t2 = pf2[d] - pf2[c-1]; t1%=3; t2%=3;
		while(t1<0) t1+=3; while(t2<0) t2+=3;
		if(t1==t2) cout<<"YES\n";
		else cout<<"NO\n";
	}
}


