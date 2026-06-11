#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

long long n, m, adj[101][101], dst[101][101], pre[101][101];

int main(){
	//IO("input.txt", "output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	set<pair<long long, long long>> st;
	for(long long i = 0; i < m; i++){
		long long a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = c, adj[b][a] = c;
		if(a > b) swap(a, b);
		st.insert({a, b});
	}
	for(long long i = 1; i <= n; i++)
		for(long long j = 1; j <= n; j++){
			if(i == j) dst[i][j] = 0;
			else if(adj[i][j]) dst[i][j] = adj[i][j];
			else dst[i][j] = 1e14;
			pre[i][j] = i;
		}
	for(long long k = 1; k <= n; k++)
		for(long long i = 1; i <= n; i++)
			for(long long j = 1; j <= n; j++)
				if(dst[i][k] + dst[k][j] < dst[i][j]){
					dst[i][j] = dst[i][k] + dst[k][j];
					pre[i][j] = pre[k][j];
				}
	for(long long i = 1; i < n; i++)
		for(long long j = 1; j <= n; j++)
			st.erase({pre[i][j], j});
	cout << st.size() << "\n";
	return 0;
}