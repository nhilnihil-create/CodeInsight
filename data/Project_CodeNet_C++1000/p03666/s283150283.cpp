#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC ("avx,avx2,fma")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define pb push_back
#define pp pop_back
#define f first
#define s second
#define endl "\n"
#define ll long long
#define ld long double
#define lb lower_bound
#define ub upper_bound
#define pii pair<int, int>
#define pss pair<string, string>
#define pll pair<long long, long long>

//template <typename T> using ordered_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

void INeedIT() {ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);}

void freopen(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}


int main() {
	INeedIT();
	ll n, a, b, c, d, x;
	cin >> n >> a >> b >> c >> d;
	if (b > a + (n - 1) * d) {
		cout << "NO";
		return 0; 
	}
	for (int i = 1; i <= n; i++) {
		x = n - i - 1;
		if (a + d * i - x * c >= b && a + c * i - x * d <= b) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	
	
	return 0;
}
