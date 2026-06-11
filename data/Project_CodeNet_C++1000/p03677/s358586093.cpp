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

int v[MAXN];
vi to[MAXN];
vi from[MAXN];

ll get_dis(int m, int from, int to) {
	if (from < to) {
		return to - from;
	} else {
		return 1 + (m - from) + (to - 1);
	}
}

void solve(){
	int n, m;
	scanf("%d%d", &n, &m);
	ll sum = 0ll;
	ll cur = 0ll;
	ll cnt = 0ll;
	REP(i, 0, n) {
		scanf("%d", &v[i]);
		if (i) {
			from[v[i]].pb(v[i - 1]);
			to[v[i - 1]].pb(v[i]);
			sum += get_dis(m, v[i - 1], v[i]);
			if (v[i - 1] > v[i]) {
				cur += 1 + (m - v[i - 1]);
				cnt++;
			}
		}
	}
	ll mn = sum - cur + cnt;
	int mini = 0;
	
	//printf("%d %lld %lld %lld\n", 0, cur, cnt, sum - cur + cnt);
	
	REP(i, 1, m) {
		REP(j, 0, SZ(from[i])) {
			cnt--;
			cur -= get_dis(m, from[i][j], i);
		}
		cur += cnt;
		REP(j, 0, SZ(to[i])) {
			cnt++;
			cur++;
		}
		if (sum - cur + cnt < mn) {
			mn = sum - cur + cnt;
			mini = i;
		}
		
		//printf("%d %lld %lld %lld\n", i, cur, cnt, sum - cur + cnt);
	}
	printf("%lld\n", mn);
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}
