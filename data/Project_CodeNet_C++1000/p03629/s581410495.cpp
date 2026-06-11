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
typedef pair <ld, ld>                                    pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

//const ll md = 1e9 + 7;//998244353;
const int xn = 2e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int Md = 1e9 + 7;
const int TM = 3;
const int Base = 257;

int n, dp[xn], last[2][26][xn], ptr, sz;
string s, ans;

int main(){
    InTheNameOfGod;
    
    cin >> s;
    n = SZ(s);
    for (int i = 0; i < 26; ++ i){
    	ptr = -1;
    	for (int j = 0; j < n; ++ j){
    		if (s[j] - 'a' == i)	ptr = j;
    		last[0][i][j] = ptr;
		}
		ptr = n;
		for (int j = n; j >= 0; -- j){
			if (j < n && s[j] - 'a' == i)	ptr = j;
			last[1][i][j] = ptr;
		}
	}
	dp[0] = n;
	for (int i = 1; i <= n; ++ i){
		if (!dp[i - 1]){
			sz = i;
			break;
		}
		int mn = inf;
		for (int c = 0; c < 26; ++ c) mn = min(mn, last[0][c][dp[i - 1] - 1]);
		if (mn == -1){
			sz = i;
			break;
		}
		dp[i] = mn;
	}
	ptr = -1;
	for (int i = 1; i <= sz; ++ i){
		for (int c = 0; c < 26; ++ c){
			if (last[1][c][ptr + 1] < dp[sz - i])	continue;
			ptr = last[1][c][ptr + 1];
			ans += char(c + 'a');
			break;
		}
	}
	cout << ans << endl;
    
	
    return 0;
}
