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
// wow, quite elegant actually. :D
// the idea is EXTREMELY simple, but of course, I overcomplicated it.
ll dp[5005][5005];
ll mod = 1e9 + 7;
int main(){
	fastio;
	ll n; cin >> n;
	string s; cin >> s;
	ll m = s.length();
	if (n == m){
		cout << 1 << endl; return 0;
	}
	dp[0][0] = 1;
	for (ll i = 1; i <= n; i++){
		for (ll j = 0; j <= i; j++){
			if ((j == 0) && (i == 1)) dp[i][j] = 1;
			else if ((j == 0) && (i > 1)) dp[i][0] = (dp[i - 1][0] + (2 * dp[i - 1][1])) % mod;
			else dp[i][j] = (dp[i - 1][j - 1] + (2 * dp[i - 1][j + 1])) % mod;
 		}
	}
	cout << dp[n][m];
}