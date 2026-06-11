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

vi divs[MAXN];

int ans[MAXN], col[MAXN];

int add_seg[MAXN];

void solve(){
	int n, l, r, m, cc;
	scanf("%d%d", &n, &m);
	//cc = 500;
	cc = (int)sqrt(m + 0.5);
	REPN(i, 1, m){
		for(int j = i; j <= m; j += i){
			divs[j].pb(i);
		}
	}
	REPN(i, 1, n){
		scanf("%d%d", &l, &r);
		if (r - l <= cc){
			REPN(j, l, r){
				REP(k, 0, SZ(divs[j])){
					if (col[divs[j][k]] != i){
						col[divs[j][k]] = i;
						ans[divs[j][k]]++;
					}
				}
			}
		} else {
			int lim = r - l + 1;
			int last = INF;
			for(int j = 1; ; j++){
				int l1 = (l + j - 1) / j;
				int r1 = r / j;
				r1 = min(r1, last - 1);
				if (l1 <= lim){
					l1 = lim + 1;
				}
				if (l1 <= r1){
					add_seg[l1]++;
					add_seg[r1 + 1]--;
				}
				if (l1 == lim + 1){
					break;
				}
				last = r1;
			}
			add_seg[1]++;
			add_seg[lim + 1]--;
		}
	}
	
	REPN(i, 1, m){
		add_seg[i] += add_seg[i - 1];
		ans[i] += add_seg[i];
		
		printf("%d\n", ans[i]);
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
