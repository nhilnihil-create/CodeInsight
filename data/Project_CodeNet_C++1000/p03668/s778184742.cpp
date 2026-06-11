#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<ll> G[Maxn];

ll g[Maxn];
void DFS(ll u, ll p){
	for(auto adj : G[u]){
		if(adj != p){
			DFS(adj, u);
			g[u] ^= g[adj];
		}
	}
	if(u == 1){
		if(g[u]) cout << "Alice\n";
		else cout << "Bob\n";
	}
	g[u] ++;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
	ll n;
	cin >> n;
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	DFS(1, -1);
	return 0;
}



