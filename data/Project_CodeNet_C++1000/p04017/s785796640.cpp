# include <bits/stdc++.h>
/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/

using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll , ll >                                  pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;//998244353;
const int xn = 1e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
string abc = "abcdefghijklmnopqrstuvwxyz";


int n, qq, L, num[xn], par[2][22][xn];

void build(){
	for (int i = 1; i <= n; ++ i){
		int l = 0, r = i, mid;
		while (r - l > 1){
			mid = (l + r) / 2;
			if (num[i] - num[mid] > L) l = mid;
			else r = mid;
		}
		par[0][0][i] = r;
		l = i, r = n + 1;
		while (r - l > 1){
			mid = (l + r) / 2;
			if (num[mid] - num[i] <= L) l = mid;
			else r = mid;
		}
		par[1][0][i] = l;
	}
	for (int j = 1; j < 20; ++ j)
		for (int i = 1; i <= n; ++ i)
			for (int k = 0; k < 2; ++ k)
				par[k][j][i] = par[k][j - 1][par[k][j - 1][i]];
	
}
void Solve(int x, int y){
	bool flag = (x < y);
	int ans = 1;
	for (int j = 19; j >= 0; -- j){
		if (flag && par[flag][j][x] < y) x = par[flag][j][x], ans += (1 << j);
		else if (!flag && par[flag][j][x] > y) x = par[flag][j][x], ans += (1 << j);
	}
	cout << ans << endl;
}


int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i) 	cin >> num[i];
	cin >> L >> qq;
	build();
	while (qq --){
		int v, u;
		cin >> v >> u;
		Solve(v, u);
	}
	
	return 0;
}
