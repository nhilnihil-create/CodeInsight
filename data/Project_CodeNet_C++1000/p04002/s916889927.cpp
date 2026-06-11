/** By @ZhakudaMagzhan **/

/*
# pragma comment(linker, "/stack:20000000")
# pragma GCC optimize("Ofast,no-stack-protector")	
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx") // */

# include <bits/stdc++.h>

# define fi first
# define se second

# define y1   WENAO
# define endl "\n"
# define ioi  exit(0)  /* 2019 */

# define mp make_pair
# define pp pop_back	
# define pb push_back

# define ub upper_bound
# define lb lower_bound

# define sz(x)   (int)x.size()
# define all(x)  x.begin(), x.end()
# define bit(x)  __builtin_popcountll(x)
# define CLOCK   clock()/(double)CLOCKS_PER_SEC
# define uniq(x) x.resize(unique(all(x))-x.begin())

/*
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
# include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;

typedef tree < int, null_type, less < int >, rb_tree_tag,
tree_order_statistics_node_update > ordered_set; // find_by_order(), order_of_key(). */

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

typedef pair <ll, ll> pll;
typedef pair <int,int> pii;

typedef vector <ll>  vll;
typedef vector <int> vi;
typedef vector <pii> vpii;


const int inf = (int) 2e9, mod = (int) 1e9 + 7;
const ll linf = (ll) 2e18;

int kob (int x, int y) { return ((ll)x * y) % mod; } 
int aza (int x, int y) { x -= y; if (x < 0) return x + mod; return x; } 
int kos (int x, int y) { x += y; if (x >= mod) return x - mod; return x; }

const int maxn = (int) 1e5 + 666, maxn2 = (int) 1e6 + 666;

map <pii, bool> used;
vector<pii>v;
ll n, m, q;

ll get (int x, int y, int d) {
  ll ans = 0;
	if (d == 1) {
		if (y+2>m) return -1;
		if (x+2>n) return -1;
		ans += used[mp (x, y)];
		ans += used[mp (x, y+1)];
		ans += used[mp (x, y+2)];

		ans += used[mp (x+1, y)];
		ans += used[mp (x+1, y+1)];
		ans += used[mp (x+1, y+2)];

		ans += used[mp (x+2, y)];
		ans += used[mp (x+2, y+1)];
		ans += used[mp (x+2, y+2)];
	}  

	if (d == 2) {
	  if (y+1>m) return -1;
	  if (y-1==0) return -1;
		if (x+2>n) return -1;
		ans += used[mp (x, y-1)];
		ans += used[mp (x, y+1)];
		ans += used[mp (x, y)];

		ans += used[mp (x+1, y)];
		ans += used[mp (x+1, y-1)];
		ans += used[mp (x+1, y+1)];

		ans += used[mp (x+2, y)];
		ans += used[mp (x+2, y-1)];
		ans += used[mp (x+2, y+1)];
	}

	if (d == 3) {
		if (y-2<=0) return -1;
		if (x+2>n) return -1;
		ans += used[mp (x, y)];
		ans += used[mp (x, y-1)];
		ans += used[mp (x, y-2)];

		ans += used[mp (x+1, y)];
		ans += used[mp (x+1, y-1)];
		ans += used[mp (x+1, y-2)];

		ans += used[mp (x+2, y)];
		ans += used[mp (x+2, y-1)];
		ans += used[mp (x+2, y-2)];		
	}

	if (d == 4) {
		if (x+1>n||x-1<=0||y+2>m) return -1;
		ans += used[mp (x, y)];
		ans += used[mp (x, y+1)];
		ans += used[mp (x, y+2)];

		ans += used[mp (x-1, y)];
		ans += used[mp (x-1, y+1)];
		ans += used[mp (x-1, y+2)];

		ans += used[mp (x+1, y)];
		ans += used[mp (x+1, y+1)];
		ans += used[mp (x+1, y+2)];
	}  

	if (d == 5) {
		if (x+1>n||x-1<=0) return -1;
	  if (y+1>m) return -1;
	  if (y-1==0) return -1;
		ans += used[mp (x, y-1)];
		ans += used[mp (x, y+1)];
		ans += used[mp (x, y)];

		ans += used[mp (x+1, y-1)];
		ans += used[mp (x+1, y)];
		ans += used[mp (x+1, y+1)];

		ans += used[mp (x-1, y-1)];
		ans += used[mp (x-1, y)];
		ans += used[mp (x-1, y+1)];		
	}

	if (d == 6) {
		if (x+1>n||x-1<=0) return -1;
		if (y-2<=0) return -1;
		ans += used[mp (x, y-2)];
		ans += used[mp (x, y-1)];
		ans += used[mp (x, y)];

		ans += used[mp (x-1, y)];
		ans += used[mp (x-1, y-1)];
		ans += used[mp (x-1, y-2)];

		ans += used[mp (x+1, y)];
		ans += used[mp (x+1, y-1)];
		ans += used[mp (x+1, y-2)];		
	}

	if (d == 7) {
	  if (x-2<=0) return-1;
		if (y+2>m) return -1;
		ans += used[mp (x, y)];
		ans += used[mp (x, y+1)];
		ans += used[mp (x, y+2)];

		ans += used[mp (x-1, y)];
		ans += used[mp (x-1, y+1)];
		ans += used[mp (x-1, y+2)];

		ans += used[mp (x-2, y)];
		ans += used[mp (x-2, y+1)];
		ans += used[mp (x-2, y+2)];
	}  

	if (d == 8) {
	  if (x-2<=0) return-1;
	  if (y+1>m) return -1;
	  if (y-1==0) return -1;
		ans += used[mp (x, y-1)];
		ans += used[mp (x, y+1)];
		ans += used[mp (x, y)];

		ans += used[mp (x-1, y)];
		ans += used[mp (x-1, y-1)];
		ans += used[mp (x-1, y+1)];

		ans += used[mp (x-2, y)];
		ans += used[mp (x-2, y-1)];
		ans += used[mp (x-2, y+1)];
	}

	if (d == 9) {
	  if (x-2<=0) return-1;
		if (y-2<=0) return -1;
		ans += used[mp (x, y)];
		ans += used[mp (x, y-1)];
		ans += used[mp (x, y-2)];

		ans += used[mp (x-1, y)];
		ans += used[mp (x-1, y-1)];
		ans += used[mp (x-1, y-2)];

		ans += used[mp (x-2, y)];
		ans += used[mp (x-2, y-1)];
		ans += used[mp (x-2, y-2)];		
	}
	return ans;
}

ll ans[150];
                                                                          
int32_t main () {
	#define FN "" // zverskii raper		
	#ifdef GOLD
		freopen (FN".in", "r", stdin);
		freopen (FN".out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
	/*unsigned int FOR; asm("rdtsc" : "=A"(FOR)); srand(FOR); // */	
	cin >> n >> m >> q;
	ll all = (n-2)*(m-2);
	for (int i = 1; i <= q; ++ i) {
		int a, b;
		cin >> a >> b;
		used[mp (a, b)] = true;
		v.pb (mp (a, b));
	}

	for (auto it: v) {
		for (int i = 1; i <= 9; ++ i) { 
		  if (get (it.fi, it.se, i) != -1) {
	  		++ ans[get (it.fi, it.se, i)];
	  	}
		}
	}

	ll sum = 0;
	for (int i = 1; i <= 9; ++ i) {
	  ans[i]/=i;
	  sum += (ans[i]);
	}

	ans[0] = all-sum;
	for (int i = 0; i <= 9; ++ i)
		cout << ans[i] << endl;
	return 0;
}


/* Jocelyn Flores */
	