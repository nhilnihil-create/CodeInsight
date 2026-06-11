#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

string s;
int dp[100001][2];

int main(){
	//IO("input.txt", "output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	dp[0][0] = 0, dp[0][1] = -1;
	for(int i = 1; i <= (int)s.length(); i++){
		dp[i][0] = (s[i - 1] == 'g') + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0] - (s[i - 1] == 'p');
	}
	cout << dp[(int)s.length()][0] << "\n";
	return 0;
}