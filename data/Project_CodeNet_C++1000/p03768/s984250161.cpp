#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iterator>

#define ios ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
#define S second
#define F first
#define pb push_back
#define nl '\n'
#define mp make_pair
#define NL cout << '\n';
#define EX exit(0)
#define all(s) s.begin(), s.end()
#define FOR(i, start, finish, k) for(int i = start; i <= finish; i += k)

const long long MXN = 1e5 + 1;
const long long MNN = 1e3 + 1;
const long long MOD = 998244353;
const long long INF = 1e18;
const long long OO = 1e9 + 500;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

llong n, m, Q, ans[MXN], u[MXN], col[MXN], d[MXN], D[MXN];
vector<int> q[MXN];

void dfs(llong x, llong C, llong d){
	if(ans[x] == 0) ans[x] = C;
	D[x] = d;
	if(d == 0) return ;
	for(int i = 0; i < q[x].size(); i++){
		int to = q[x][i];
		if(ans[to] == 0) dfs(to, C, d - 1);
		if(D[to] < d - 1){
			dfs(to, C, d - 1);
		}
	}
}

int main(){
	ios;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int l, r;
		cin >> l >> r;
		q[l].pb(r);
		q[r].pb(l);
	}cin >> Q;
	for(int i = 1; i <= Q; i++){
		cin >> u[i] >> d[i] >> col[i];
	}
	for(llong i = Q; i >= 1; i--){
		if(ans[u[i]] == 0 || D[u[i]] < d[i]){
			dfs(u[i], col[i], d[i]);
		}
	}
	for(int i = 1; i <= n; i++){
		cout << ans[i] << nl;
	}
	return 0;
}
/*
 5 0
 5
 3
 3
 6
 1
 3
 4
 0
 3
 
 5
 5
 3
 3
 6
 1
 3
 4
 5
 3
 
 
 */
