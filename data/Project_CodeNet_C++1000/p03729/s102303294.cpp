#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

string a, b, c;

int main(){
	//IO("input.txt", "output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> c;
	if(a.back() == b[0] && b.back() == c[0]) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}