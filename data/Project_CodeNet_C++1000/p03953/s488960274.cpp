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

int per[MAXN];
int d[MAXN];
int x[MAXN];

int d1[MAXN];
int used[MAXN];

ll ans[MAXN];

vi cycle;

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n){
		scanf("%d", &x[i]);
	}
	REP(i, 1, n){
		d[i] = x[i] - x[i - 1];
		per[i] = i;
	}
	int m;
	ll k;
	scanf("%d%lld", &m, &k);
	REP(i, 0, m){
		int a;
		scanf("%d", &a);
		swap(per[a], per[a - 1]);
	}
	REP(i, 1, n){
		if (used[i]){
			continue;
		}
		cycle.clear();
		for(int j = i; !used[j]; j = per[j]){
			cycle.pb(j);
			used[j] = 1;
		}
		int offset = k % SZ(cycle);
		REP(j, 0, SZ(cycle)){
			d1[cycle[j]] = d[cycle[(j + offset) % SZ(cycle)]];
		}
	}
	ans[0] = x[0];
	REP(i, 1, n){
		ans[i] = ans[i - 1] + d1[i];
	}
	REP(i, 0, n){
		printf("%lld\n", ans[i]);
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
