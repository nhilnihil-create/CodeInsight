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

const int MAXN = 1e5 + 5, MAXD = 11;

vi g[MAXN];

int col[MAXN][MAXD];
int cur_col;

int q_v[MAXN], q_d[MAXN], q_c[MAXN];

int ans[MAXN];

void dfs(int s, int d) {
	for(int i = d; i >= 0 && !col[s][i]; i--) {
		col[s][i] = cur_col;
	}
	if (d == 0) {
		return;
	}
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		if (!col[to][d - 1]) {
			dfs(to, d - 1);
		}
	}
}

void solve(){
	int n, m, a, b, q;
	scanf("%d%d", &n, &m);
	REP(i, 0, m){
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	scanf("%d", &q);
	REP(i, 0, q){
		scanf("%d%d%d", &q_v[i], &q_d[i], &q_c[i]);
	}
	for(int i = q - 1; i >= 0; i--) {
		if (!col[q_v[i]][q_d[i]]) {
			cur_col = q_c[i];
			dfs(q_v[i], q_d[i]);
		}
	}
	REPN(i, 1, n){
		printf("%d\n", col[i][0]);
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
