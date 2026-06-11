#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(x) x.begin(), x.end()

#define mp make_pair
#define in insert
#define er erase
#define con continue
#define pb push_back
#define sc scanf
#define pr printf
#define ub upper_bound
#define lb lower_bound
#define s second
#define f first
#define int long long

const long long infl = 1e18; 
const int N = 3e5 + 300, N2 = 2e3, inf = 1e9 + 200;

set <int> S;
vector <int> g[N];
int n, m, k;
int a[N], res;
string ss;

void go(int l, int r){
//	cout << l << " " << r << "\n";
	if (l == r){
		res += g[l].size() / 2;
	}
	else{
		if (g[l].size() < g[r].size()) swap(g[l], g[r]);
		res += min(g[l].size(), g[r].size());
		int val = g[l].size() - g[r].size();
//		cout << val;
		for (int i = 1; i < g[l].size(); i++){
			if (val <= 1) break;
			if (g[l][i] == g[l][i - 1]){
				val -= 2;
				res++;
				i++;
			}
		}
	}
//	cout << endl;
}

main (){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++){
		g[a[i] % m].pb(a[i]);
	}
	go(0, 0);
	for (int l = 1, r = m - 1; l <= r; l++, r--){
		go(l, r);
	}
	cout << res;
	return 0;
}










