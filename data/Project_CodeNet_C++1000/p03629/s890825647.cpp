//	Totally unrelated and not AT ALL stolen from hohohaha's, generic_placeholder_name's or katoriyuu's template
#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("avx")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define gcd __gcd
#define rep(i,s,end) for(int i = (s); i <  (end); ++i)
#define rep0(i, end) for(int i =   0; i <= (end); ++i)
#define rep1(i, end) for(int i =   1; i <= (end); ++i)
#define lb lower_bound
#define ub upper_bound

#define vt vector
#define endl "\n"

#define fileopen(filename, in_type, out_type) if (fopen(filename in_type, "r")) {freopen(filename in_type, "r", stdin);freopen(filename out_type, "w", stdout);}
#define local_input(x) if (x && fopen("input.txt","r")) freopen("input.txt","r",stdin);
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#define fscan(x)   scanf("%d",  &x)
#define fscandb(x) scanf("%lf", &x)
#define fscanll(x) scanf("%lld",&x)
//	Until next time, remember:
//			You are closer than you think.
//						_Dan Lok_

#define db double
#define ll long long
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define pi 3.1415926535897932	//faster than pi = acos(-1); but sometimes doesn't work?
//	srand(chrono::steady_clock::now().time_since_epoch().count());
//	freopen("input.txt","r",stdin);

#define lnode id<<1
#define rnode id<<1|1
#define mn 200007
string s;
int nx[26];
int dp[mn];
int after[mn], afterc[mn];
signed main()
{
	// fastio;
	cin >> s; fill(nx, end(nx),s.length());
	for(int i = s.length()-1, nchar = 0; i > -1; nx[s[i]-'a'] = i,--i, nchar = 0){
		for(int j = 0; j < 26; ++j) 
			if(dp[nx[nchar]] > dp[nx[j]]) nchar = j;
		dp[i] = dp[nx[nchar]]+1, after[i] = nx[afterc[i] = nchar];
	}
	int st = -1;
	rep(i,0,26) if(nx[i] != s.length()){
		if(st == -1 || dp[nx[i]] < dp[st]) st = nx[i];
	} else {
		cout << char(i+'a'); return 0;
	}
	cout << s[st];
	while(after[st] < s.length()) cout << s[st = after[st]]; 
	cout << char(afterc[st]+'a') << endl;
	// rep(i,0,s.length()) cerr << dp[i] << ' '; cerr << endl;
	// rep(i,0,s.length()) cerr << after[i] << ' '; cerr << endl;
	return 0;
}
// with the aura of Dora, AC!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Why is there a one in my row of exclamation marks?

