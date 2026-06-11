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

const int MAXN = 1e5 + 5;

int a[MAXN];

void solve(){
	int n, m, ind[2], cnt;
	scanf("%d%d", &n, &m);
	ind[0] = ind[1] = -1;
	cnt = 0;
	REP(i, 0, m){
		scanf("%d", &a[i]);
		if (a[i] & 1){
			if (cnt < 2){
				ind[cnt] = i;
			}
			cnt++;
		}
	}
	if (cnt > 2){
		printf("Impossible\n");
		return;
	}
	if (cnt > 0){
		swap(a[0], a[ind[0]]);
	}
	if (cnt > 1){
		swap(a[m - 1], a[ind[1]]);
	}
	REP(i, 0, m){
		printf("%d ", a[i]);
	}
	if (m == 1 && a[0] != 1){
		a[0]--;
		a[1] = 1;
		m = 2;
	} else {
		a[0]++;
		a[m - 1]--;
		if (a[m - 1] == 0){
			m--;
		}
	}
	printf("\n%d\n", m);
	REP(i, 0, m){
		printf("%d ", a[i]);
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