#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define for1(i, a, b) for(i = a; i <= b; ++i)
#define for0(i, a, b) for(i = a; i < b; ++i)
#define forw1(i, a, b) for(i = a; i >= b; --i)
#define forw0(i, a, b) for(i = a - 1; i >= b; --i)
#define fora(v, a) for(auto v : a)
#define bp __builtin_popcount
#define bpll __builtin_popcountll

using namespace std;
using cd = complex<double>;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<cd> vcd;
typedef vector<ii> vii;
typedef vector<vector<int> > vvi;

const int modd1 = 1e9 + 7, modd2 = 998244353, maxn = 1e5 + 10, K = 26, inf = 1e9, infll = 1e18;
const double pi = acos(-1);
int n, m, ans[maxn];
ii a[maxn];

bool cmp(ii a, ii b){
	if(a.fi == b.fi){
		return a.se < b.se;
	}
	return a.fi > b.fi;
}

void solve(){
	int j, k, l, r; cin >> n ;
	for(int i = 1; i <= n; ++i){
		cin >> a[i].fi; a[i].se = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1, pick = i, val = a[pick].fi; i <= n;){
		if(i <= n && a[i].fi == a[i + 1].fi) ++i;
		int it = i + 1;
		ans[a[pick].se] += (it - 1) * (val - a[it].fi);
		val = a[it].fi;
		pick = (a[pick].se > a[it].se ? it : pick);
		i = it; 
	}
	for(int i = 1; i <= n; ++i) cout << ans[i] << '\n';
}

signed main() {
    //freopen(".INP", "r", stdin);
    //freopen(".OUT", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
