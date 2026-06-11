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
vector <int> g;
int n, m, k;
int a[400][400], x[N];
string ss;

main (){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	int res = n;
	for (int t = 0; t < m; t++){
		vector <int> b(m + 1, 0);
		for (int i = 0; i < n; i++){
			int id = 0;
			for (int j = 0; j < m; j++){
				if (x[a[i][j]] != 1) {
					id = a[i][j];
					break;
				}
			}
			b[id]++;
		}
		int mx = -1, id = 0;
		for (int i = 1; i <= m; i++){
			if (b[i] > mx){
				mx = b[i];
				id = i;
			}
		}
//		cout << endl << endl;
		res = min(res, mx);
		x[id] = 1;
		
	//	break;
		/*
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
	}
	cout << res;
	return 0;
}










