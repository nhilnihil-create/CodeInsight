#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int x, y;

int main(){
	//IO("input.txt", "output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> y;
	if(x == 4 || x == 6 || x == 9 || x == 11) x = 1;
	else if(x == 2) x = 2;
	else x = 0;
	if(y == 4 || y == 6 || y == 9 || y == 11) y = 1;
	else if(y == 2) y = 2;
	else y = 0;
	cout << ((y == x) ? "Yes\n" : "No\n");
	return 0;
}