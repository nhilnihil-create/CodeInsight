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

const int MAXN = 305;

int v[MAXN][MAXN], top[MAXN];
int cnt[MAXN];
int deleted[MAXN];

void solve(){
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = 0;
	REP(i, 0, n) {
		REP(j, 0, m) {
			scanf("%d", &v[i][j]);
		}
		cnt[v[i][0]]++;
		ans = max(ans, cnt[v[i][0]]);
	}
	REP(i, 1, m) {
		int maxi = -1;
		REPN(j, 1, m) {
			if (!deleted[j] && (maxi == -1 || cnt[j] > cnt[maxi])) {
				maxi = j;
			}
		}
		cnt[maxi] = 0;
		deleted[maxi] = 1;
		REP(j, 0, n) {
			int fl = 0;
			for(; deleted[v[j][top[j]]]; top[j]++, fl = 1);
			if (fl) {
				cnt[v[j][top[j]]]++;
			}
		}
		int cur = 0;
		REP(j, 0, n) {
			cur = max(cur, cnt[v[j][top[j]]]);
		}
		ans = min(ans, cur);
		//printf("delete %d, value %d\n", maxi, cur);
	}		
	printf("%d\n", ans);
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}
