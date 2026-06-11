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

const int modd1 = 1e9 + 7, modd2 = 998244353, maxn = 2e5 + 10, K = 26, inf = 1e9, infll = 1e18;
const double pi = acos(-1);
int n, m, f[maxn], pos[maxn][K + 2];
string A;

void solve(){
	int i, j, k, l, r; cin >> A;
	n = A.length();
	f[n] = 1;
	for0(i, 0, K){
		pos[n][i] = n;
	}
	forw0(i, n, 0){
		for0(j, 0, K){
			pos[i][j] = pos[i + 1][j];
		}
		pos[i][A[i] - 'a'] = i;
		f[i] = n;
		for0(j, 0, K){
			f[i] = min(f[i], f[pos[i][j] + 1] + 1);
		}
	}
	int p = 0;
	for(i = f[0]; i; i--){
		for0(j, 0, K){
			if(f[pos[p][j] + 1] + 1 == i){
				cout << char(j + 'a');
				p = pos[p][j] + 1;
				break;
			}
		}	
	}
}

signed main() {
    //freopen(".INP", "r", stdin);
    //freopen(".OUT", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
