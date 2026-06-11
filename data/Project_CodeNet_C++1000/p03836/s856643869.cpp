#include <bits/stdc++.h>
//#include <atcoder/all>
#define INF 1000000007
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define print(x) cout << x << "\n"
#define print2(x, y) cout << x << " " << y << "\n"
#define printv(vec) rep(lp, vec.size()) cout << vec[lp] << " "; print(""); 
#define show(x) cerr << #x << " = " << x << "\n";
#define ALL(v) v.begin(), v.end()
#define SUM(v) accumulate(ALL(v), 0)
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))
#define pb(x) push_back(x)
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
//using namespace atcoder;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vs = vector<string>;
//using mint = modint998244353;
//ll mod = 998244353;
//using mint = modint1000000007;
ll mod = 1000000007;
 
void Main(){

	ll sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;

	rep(i, ty - sy) cout << "U";
	rep(i, tx - sx) cout << "R";
	rep(i, ty - sy) cout << "D";
	rep(i, tx - sx) cout << "L";

	cout << "L";
	rep(i, ty - sy + 1) cout << "U";
	rep(i, tx - sx + 1) cout << "R";
	cout << "D";

	cout << "R";
	rep(i, ty - sy + 1) cout << "D";
	rep(i, tx - sx + 1) cout << "L";
	cout << "U" << endl;

}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll t = 1;
	//cin >> t;
	rep(i, t) Main();
	return 0;
	
}



