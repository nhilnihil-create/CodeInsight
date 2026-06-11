#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 1e5 + 5;

vi g[MAXN];

int v[MAXN];
ll dp[MAXN];

int used[MAXN];

int dfs(int s){
	used[s] = 1;
	ll dp_sum = 0, dp_mx = 0;
	REP(i, 0, SZ(g[s])){
		int to = g[s][i];
		if (!used[to]){
			if (dfs(to)){
				return 1;
			}
			dp_sum += dp[to];
			dp_mx = max(dp_mx, dp[to]);
		}
	}
	if (SZ(g[s]) > 1) {
		ll a = dp_sum - v[s];
		ll b = v[s] - a;
		if (a < 0 || b < 0 || a > dp_sum - dp_mx){
			//printf("%d %lld %lld %lld %lld\n", s, dp_sum, dp_mx, a, b);
			return 1;
		}
		dp[s] = b;
	} else {
		dp[s] = v[s];
	}
	return 0;
}

void solve(){
	int n;
	scanf("%d", &n);
	REPN(i, 1, n){
		scanf("%d", &v[i]);
	}
	REP(i, 1, n){
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	if (n == 2){
		if (v[1] == v[2]){
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		return;
	}
	int s = 1;
	REPN(i, 1, n){
		if (SZ(g[i]) > 1){
			s = i;
		}
	}
	if (dfs(s) || dp[s]){
		printf("NO\n");
	} else {
		printf("YES\n");
	}
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}
