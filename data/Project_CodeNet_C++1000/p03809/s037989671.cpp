#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC target ("avx")
#pragma GCC target ("avx2")
#pragma GCC target ("fma")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("unroll-loops, no-stack-protector")
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pci pair <char, int>
#define pld pair <ld, ld>
#define ppld pair <pld, pld>
#define ppll pair <pll, pll>
#define pldl pair <ld, ll>
#define vll vector <ll>
#define vvll vector <vll>
#define vpll vector <pll>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define mll map <ll, ll>
#define fastmap gp_hash_table
#define cd complex <double>
#define vcd vector <cd>
#define PI 3.14159265358979
#pragma 03
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
ll n; 
ll a[100005];
vll adj[100005];
void dfs(ll u, ll p){
	ll sum = 0, mx = 0;
	for (ll i = 0; i < adj[u].size(); i++){
		ll v = adj[u][i]; if (v == p) continue;
		dfs(v, u); mx = max(mx, a[v]); sum += a[v];
	}
	ll ops = min(sum - mx, sum / 2);
	if (adj[u].size() == 1) return;
	if (a[u] > sum){
		cout << "NO\n"; exit(0);
	}
	if ((sum - a[u] > ops) && (adj[u].size() > 1)){
		cout << "NO\n"; exit(0);
	}
	a[u] = 2 * a[u] - sum;
	if (a[u] < 0){
		cout << "NO\n"; exit(0);
	}
}
int main(){
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> a[i];
	if (n == 2){
		if (a[0] == a[1]) cout << "YES\n";
		else cout << "NO\n"; 
		return 0;
	}
	for (ll i = 0; i < n - 1; i++){
		ll u, v; cin >> u >> v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	for (ll i = 0; i < n; i++){
		if (adj[i].size() > 1){
			dfs(i, i); 
			if (a[i] != 0) cout << "NO\n";
			else cout << "YES\n";
			return 0;
		}
	}
}