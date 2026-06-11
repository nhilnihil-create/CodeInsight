#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define ordered_set tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update>
#pragma 03
using namespace std;
using namespace __gnu_pbds;
deque <ll> dq;
void solve(ll k){
	if (k == 1) return; 
	else if (k % 2 == 1){
		solve(k - 1); dq.push_front(dq.size() + 1);
	}
	else{
		solve(k / 2); dq.pb(dq.size() + 1);
	}
}
int main(){
	ll n; cin >> n; n++; solve(n);
	cout << dq.size() * 2 << endl;
	for (ll i = 0; i < dq.size(); i++) cout << dq[i] << " ";
	for (ll i = 0; i < dq.size(); i++) cout << i + 1 << " ";
}