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
ll pret[100005][2], pres[100005][2]; 
int main(){
	fastio;
	string s, t; cin >> s >> t;
	for (ll i = 1; i <= s.length(); i++){
		pres[i][0] = pres[i - 1][0]; pres[i][1] = pres[i - 1][1];
		if (s[i - 1] == 'A') pres[i][0]++; else pres[i][1]++;
	}
	for (ll i = 1; i <= t.length(); i++){
		pret[i][0] = pret[i - 1][0]; pret[i][1] = pret[i - 1][1];
		if (t[i - 1] == 'A') pret[i][0]++; else pret[i][1]++;
	}
	ll q; cin >> q;
	while (q--){
		ll a, b, c, d; cin >> a >> b >> c >> d;
		ll cnta1 = pres[b][0] - pres[a - 1][0], cntb1 = pres[b][1] - pres[a - 1][1];
		ll cnta2 = pret[d][0] - pret[c - 1][0], cntb2 = pret[d][1] - pret[c - 1][1];
		ll cnt1 = 2 * cnta1 + cntb1, cnt2 = 2 * cnta2 + cntb2;
		if ((cnt2 - cnt1) % 3 == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}