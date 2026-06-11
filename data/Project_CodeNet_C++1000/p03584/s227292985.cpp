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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

int a[MAXN], b[MAXN];

ll get(int n, int mask) {
	ll ans = 0ll;
	REP(i, 0, n) {
		if ((mask | a[i]) == mask) {
			ans += b[i];
		}
	}
	return ans;
}

void solve(){
	int k, n;
	scanf("%d%d", &n, &k);
	REP(i, 0, n) {
		scanf("%d%d", &a[i], &b[i]);
	}
	ll ans = get(n, k);
	for(int i = 30; i >= 0; i--) {
		if (k & (1 << i)) {
			int mask = k ^ (1 << i);
			mask |= (1 << i) - 1;
			ans = max(ans, get(n, mask));
		}
	}
	cout << ans << endl;
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}
