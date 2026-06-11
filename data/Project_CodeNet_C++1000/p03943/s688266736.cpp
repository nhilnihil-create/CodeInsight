#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int cnd[3];

int main(){
	//IO("input.txt", "output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 0; i < 3; i++) cin >> cnd[i];
	sort(cnd, cnd + 3);
	cout << ((cnd[2] == cnd[0] + cnd[1]) ? "Yes\n" : "No\n");
	return 0;
}