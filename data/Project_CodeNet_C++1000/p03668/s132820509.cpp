/// ITNOG :)))
/// SAliB
#include <bits/stdc++.h>

using namespace std;

#define pb                      push_back
#define pp                      pop_back
#define mp                      make_pair
#define fi                      first
#define sec                     second
#define xmax(x,y)               ((x) = max((x),(y)))
#define xmin(x,y)               ((x) = min((x),(y)))
#define all(x)                  (x).begin(),(x).end()
#define mem(x , y)              memset(x , y , sizeof(x))
#define _                       ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define debug1(a)               cout << string(40 , '*') << '\n' << #a << " ---> " << a << '\n';
#define debug2(a , b)           cout << string(40 , '*') << '\n' << #a << " ---> " << a << '\n' << #b << " ---> " << b << '\n';
#define debug3(a , b , c)       cout << string(40 , '*') << '\n' << #a << " ---> " << a << '\n' << #b << " ---> " << b << '\n' << #c << " ---> " << c << '\n';
#define debug4(a , b , c , d)   cout << string(40 , '*') << '\n' << #a << " ---> " << a << '\n' << #b << " ---> " << b << '\n' << #c << " ---> " << c << '\n' << #d << " ---> " << d << '\n';
#define connect(a , b , c)      a[b].pb(c) , a[c].pb(b)
//
typedef long long int ll            ;
typedef unsigned long long int ull  ;
typedef unsigned int uint           ;
typedef long double ld              ;
typedef string str                  ;
typedef pair < int , int > pii      ;
typedef pair < pii , int > ppi      ;
typedef pair < int , pii > pip      ;
typedef pair < ll , ll> pll         ;
typedef pair < ll , pll> plp        ;
typedef pair < pll , ll> ppl        ;
typedef vector < ll > vl            ;
typedef vector < ld > vld           ;
typedef vector < int > vi           ;
typedef vector < str > vs           ;
//
inline int   iin()  { int x   ; scanf("%d" , &x)   ;  return x; }
inline ll    lin()  { ll  x   ; scanf("%lld" , &x) ;  return x; }
inline ll    Lin()  { ll  x   ; scanf("%I64d" , &x);  return x; }
//
inline int   iout(int  x)  { printf("%d" , x)   ;  }
inline ll    lout(ll   x)  { printf("%lld" , x) ;  }
inline ll    Lout(ll   x)  { printf("%I64d" , x);  }
//
const int maxn4 = 1e4 + 85 , maxn5 = 1e5 + 69 , maxn6 = 1e6 + 85 , maxn7 = 1e7 + 69 , maxn8 = 1e8 + 85 , maxn9 = 1e9 + 69 , modi1 = 1e7 + 7 , modi2 = 1e9 + 7;
const ll mod1 = 1e7 + 7 , mod2 = 1e9 + 7;
int mn = INT_MAX , mx = INT_MIN;
//
vi g[maxn6];
int dfs(int v , int p = -1)
{
	int ans = 0;
	for(int u : g[v])
		if (u != p)
			ans ^= dfs(u , v) + 1;
	return ans;
}
int main()
{_
	int n;cin >> n;
	for(int i = 0; i < n - 1; i++)
    {
		int u , v;cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}
	cout << (dfs(0) ? "Alice" : "Bob");
}
