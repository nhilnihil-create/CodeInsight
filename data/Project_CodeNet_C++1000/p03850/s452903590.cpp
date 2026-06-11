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

ll v[MAXN];

char op[MAXN];

char c[10];

void refresh(ll cur, ll &ans, int &fl){
	//printf("%lld %lld\n", ans, cur);
	if (!fl){
		ans = cur;
	}
	ans = max(ans, cur);
	fl = 1;
}

void solve(){
	int n;
	scanf("%d%lld", &n, &v[0]);
	ll sum = 0ll;
	REP(i, 1, n){
		scanf("%s%lld", &c[0], &v[i]);
		op[i] = c[0];
		sum += v[i];
	}
	op[n] = '-';
	n++;
	int fl = 0;
	ll l_val = v[0];
	ll ans = 0ll;
	REPN(i, 1, n){
		if (op[i] == '+'){
			l_val += v[i];
			sum -= v[i];
		} else {
			ll v2 = v[i];
			REPN(j, i + 1, n){
				if (op[j] == '-'){
					break;
				}
				v2 += v[j];
			}
			//printf("%lld %lld %lld\n", l_val, -v2, sum - v2);
			refresh(l_val - v2 + sum - v2, ans, fl);
			l_val -= v[i];
			sum -= v[i];
		}	
	}
	//refresh(l_val, ans, fl);
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
