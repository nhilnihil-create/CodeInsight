//	Totally unrelated and not AT ALL stolen from hohohaha's, generic_placeholder_name's or katoriyuu's template
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;

#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

#define int ll
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define pi 3.1415926535897932	
//	srand(chrono::steady_clock::now().time_since_epoch().count());
//	freopen("input.txt","r",stdin);

#define mn 100002
int n,m, root = 1;
int a[mn];
vi adjlist[mn];
void fuck_no(){cout << "NO"; exit(0);}

void dfs(const int& u, const int& p)
{
	if(adjlist[u].size() > 1){
		int sum = 0;
		for(int& i : adjlist[u]) if(i != p){
			dfs(i,u); sum += a[i];
			if(a[i] > a[u]) fuck_no();
		}
		int x = sum-a[u], y = a[u]-x;
		if(x < 0 || y < 0) fuck_no();
		a[u] = y;
	}
}

signed main()
{
	fastio;
	cin >> n; rep1(i,n){
		cin >> a[i];
	}
	if(n == 2){
		cout << (a[1] == a[2] ? "YES\n" : "NO\n");
		return 0;
	}
	rep(i,1,n){
		int x,y; cin >> x >> y;
		adjlist[x].pb(y), adjlist[y].pb(x);
		if(root == 1){
			if(adjlist[x].size() > 1) root = x;
			if(adjlist[y].size() > 1) root = y;
		}
	}
	dfs(root, 0);
	cout << (a[root] ? "NO\n" : "YES\n");
	return 0;
}
// with the aura of Dora, AC!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Why is there a one in my row of exclamation marks?
