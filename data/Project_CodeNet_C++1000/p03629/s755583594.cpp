//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
//#pragma GCC target("avx,avx2")
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")

//# include <x86intrin.h>
# include <bits/stdc++.h>

# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
 
template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _USE_MATH_DEFINES_
#define ll long long
#define ld long double
#define Accepted 0
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define every(x) x.begin(),x.end()
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define For(i,x,y)  for (ll i = x; i <= y; i ++) 
#define FOr(i,x,y)  for (ll i = x; i >= y; i --)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// ROAD to...                                                                                                                                                                                                                Red

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

const double eps = 0.000001;
const ld pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const ll MOD = 1e18 + 9;
const ll INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;                                          
const int M = 22;
const int pri = 997;
const int Magic = 2101;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

set<string> was;
string t;
int dp[N];
int pos[N];
int from[N];
char nxt[N];

int main () {
	SpeedForce;
	string s;
	cin >> s;
	int n = sz(s);
	s = char(1+'z') + s;
	
	for (int i = 0; i < 26; ++i) pos[i] = n+1;
	for (int i = n; ~i; --i) {
		int mn = 0;
		for (int c = 0; c < 26; ++c) {
			if(dp[pos[mn]] > dp[pos[c]]) mn = c;
		}
		dp[i] = dp[pos[mn]] + 1;
		from[i] = pos[mn];
		nxt[i] = char(mn+'a');
		pos[s[i]-'a'] = i;
	} 
	
	int x = 0;
	while(x <= n) {
		cout << nxt[x];
		x = from[x];
	}
	
	return Accepted;
}

// B...a
