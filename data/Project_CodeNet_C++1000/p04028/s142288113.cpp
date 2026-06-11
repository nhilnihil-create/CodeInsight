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

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 5e3 + 5;

ll f[MAXN], f_inv[MAXN];

ll dp0[MAXN], dp0_tmp[2][MAXN];

ll pow_mod(ll a, ll st){
	ll ans = 1ll;
	for(; st; st /= 2ll){
		if (st & 1){
			ans = (ans * a) % MOD;
		}
		a = (a * a) % MOD;
	}
	return ans;
}

void init_c(){
	f[0] = 1;
	REP(i, 1, MAXN){
		f[i] = (f[i - 1] * i) % MOD;
	}
	f_inv[MAXN - 1] = pow_mod(f[MAXN - 1], MOD - 2);
	for(int i = MAXN - 2; i >= 0; i--){
		f_inv[i] = (f_inv[i + 1] * (i + 1)) % MOD;
	}
}

ll get_c(int i, int j){
	if (i < 0 || j < 0 || j > i){
		return 0ll;
	}
	ll ans = (f[i] * f_inv[j]) % MOD;
	ans = (ans * f_inv[i - j]) % MOD;
	return ans;
}

char s[MAXN];

void solve(){
	init_c();
	
	int n, len;
	scanf("%d%s", &n, &s[0]);
	len = strlen(s);
	
	dp0_tmp[0][0] = 1;
	dp0[0] = 1;
	REP(i, 0, n){
		int ind = i & 1;
		REP(j, 0, n){
			dp0_tmp[ind ^ 1][j] = 0;
		}
		REP(j, 0, n){
			int j1 = max(j - 1, 0);
			dp0_tmp[ind ^ 1][j1] = (dp0_tmp[ind ^ 1][j1] + dp0_tmp[ind][j]) % MOD;
			
			dp0_tmp[ind ^ 1][j + 1] = (dp0_tmp[ind ^ 1][j + 1] + 2ll * dp0_tmp[ind][j]) % MOD;
		}
		dp0[i + 1] = dp0_tmp[ind ^ 1][0];
	}
	
	ll ans = 0ll;
	REP(i, 0, n){
		ll cur = dp0[i];
		int i1 = n - (i + 1);
		int j1 = len - 1;
		if ((i1 + j1) & 1){
			continue;
		}
		int up_moves = (i1 + j1) / 2;
		int down_moves = i1 - up_moves;
		if (up_moves < 0 || down_moves < 0){
			continue;
		}
		ll mul = get_c(i1, up_moves) - get_c(i1, up_moves + 1);
		if (mul < 0){
			mul += MOD;
		}
		
		//printf("%d %d %lld %lld %lld\n", i1, j1, dp0[i], mul, pow_mod(2ll, down_moves));
		
		mul = (mul * pow_mod(2ll, down_moves)) % MOD;
		
		ans = (ans + cur * mul) % MOD;
	}
	
	printf("%lld\n", ans);
}	

int main(){

	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}