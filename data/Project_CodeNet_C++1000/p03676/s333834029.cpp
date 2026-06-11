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

const int MAXF = 1e5 + 5;

ll f[MAXF], f_inv[MAXF];

ll pow_mod(ll a, ll st) {
	ll ans = 1ll;
	for(; st; st >>= 1ll) {
		if (st & 1) {
			ans = (ans * a) % MOD;
		}
		a = (a * a) % MOD;
	}
	return ans;
}

ll get_inv(ll v) {
	return pow_mod(v, MOD - 2);
}

void gen_f() {
	f[0] = 1;
	REP(i, 1, MAXF) {
		f[i] = (f[i - 1] * i) % MOD;
	}
	f_inv[MAXF - 1] = get_inv(f[MAXF - 1]);
	for(int i = MAXF - 2; i >= 0; i--) {
		f_inv[i] = (f_inv[i + 1] * (i + 1)) % MOD;
	}
}

ll get_c(int i, int j) {
	if (j > i || j < 0) {
		return 0ll;
	}
	return (((f[i] * f_inv[j]) % MOD) * f_inv[i - j]) % MOD;
}

int ind[MAXN];
int ind1, ind2;


void solve(){
	gen_f();
	int n;
	scanf("%d", &n);
	REPN(i, 1, n + 1) {
		int a;
		scanf("%d", &a);
		if (ind[a]) {
			ind1 = ind[a];
			ind2 = i;
		}
		ind[a] = i;
	}
	REPN(k, 1, n + 1) {
		ll v0 = get_c(n - 1, k);
		ll v2 = get_c(n - 1, k - 2);
		ll v11 = get_c(n - 1, k - 1);
		ll v12 = get_c(ind1 - 1 + n + 1 - ind2, k - 1);
		ll v1 = (MOD + v11 + v11 - v12) % MOD;
		ll ans = (v0 + v1 + v2) % MOD;
		printf("%lld\n", ans);
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
