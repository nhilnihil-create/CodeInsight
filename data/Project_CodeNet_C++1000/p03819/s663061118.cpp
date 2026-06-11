//### In The Name Of GOD ###

//%% Remember; (((He))) is The (((Accepter))) %%

// GOD IS GREATER ...

#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef long double ld ;

#define int ll
#define pb push_back
#define bp pop_back
#define pf push_front
#define fp pop_front
#define X first
#define Y second
#define IO ios_base::sync_with_stdio(false);
#define sz(a) (int)(a.size())
#define sg(a, b) (a + b - 1) / b

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 8 * 1000 * 1000 + 200;
const int MAXN =  100 * 1000 + 10;
const int MLOG = 18;
const int NMAX = 20;

struct fen{
	int fn[MAXN];
	
	void add(int idx, int val){
		for (idx++; idx < MAXN; idx += idx & -idx)
			fn[idx] += val;
	}

	void addr(int l, int r, int val = 1){
		add(l, val);
		add(r + 1, -val);
	}

	int ansq(int idx){
		int ans = 0;
		for (idx++; idx > 0; idx -= idx & -idx)
			ans += fn[idx];
		return ans;
	}
}me;

signed main(){
	IO;
	int n, m;
	cin >> n >> m;
	int seg[n][2];
	vector<pair<int, int>> vc[3 * MAXN];
	for(int i = 0; i < n; i++){
   		cin >> seg[i][0] >> seg[i][1];
		vc[seg[i][1] - seg[i][0] + 1].pb({seg[i][0], seg[i][1]});
	}
	int x = 0;
	for(int i = 1; i <= m; i++){
		int ans = 0;
		for(int j = 0; j < sz(vc[i]); j++){
			me.addr(vc[i][j].X, vc[i][j].Y);
			x++;
		}
		for(int j = i; j <= m; j += i){
			ans += me.ansq(j);
		}
		cout << ans + n - x << endl;
	}
}