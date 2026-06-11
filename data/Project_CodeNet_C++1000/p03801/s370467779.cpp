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

pair<ll, int> pp[MAXN];

ll ans[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	REPN(i, 1, n){
		scanf("%lld", &pp[i]._1);
		pp[i]._2 = i;
	}
	sort(pp, pp + n + 1);
	reverse(pp, pp + n + 1);
	int mn = n + 1;
	for(int i = 0; i < n; ){
		int j;
		for(j = i; pp[j]._1 == pp[i]._1; j++){
			mn = min(mn, pp[j]._2);
		}
		ans[mn] += (pp[i]._1 - pp[j]._1) * j;
		//printf("%d %lld\n", mn, ans[mn]);
		i = j;
	}
	REPN(i, 1, n){
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
