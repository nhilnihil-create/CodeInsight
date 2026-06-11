#include "bits/stdc++.h"

//region Template
#include "ext/pb_ds/assoc_container.hpp"
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int MOD = 1000000007;

using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

#define finish(x) cout << x; exit(0);
#define fastIO cin.tie(0); cin.sync_with_stdio(false);

void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

//const string USCAO_TAG = "mountains";
void usaco(const string& USACO_TAG) { setIn(USACO_TAG + ".in"); setOut(USACO_TAG + ".out"); }
void print() {}
template<typename T, typename... Args>
void print(T firstArg, Args... args) {
	#ifdef LOCAL
	cout << firstArg << "\t";
	print(args...);
	#endif
}
//endregion

/* Notes:
 * Farah </3
 */

const int MAXN = 1e6 + 6;
const int INF = 2e9;


ll dp[MAXN];
ll pre[MAXN];

int main() {
	#ifdef LOCAL
	setIn("in.txt");
	setOut("out.txt");
	#endif

	ll n;
	cin >> n;

	dp[0] = 1;
	pre[0] = 1;
	for(int i = 1; i < n; i++){
		dp[i] = pre[i - 1] + 1;

		if(i > 1){
			dp[i] -= dp[i - 2];
			if(dp[i] < 0){
				dp[i] += MOD;
			}
		} else if(i == 1){
			dp[i] -= 1;
		}

		pre[i] = (pre[i - 1] + dp[i]) % MOD;
	}



	ll ans = (dp[n - 1] + (n - 1) * (n - 1) + 1) % MOD;
	for(int i = 1; i < n; i++){
		ans = (ans + dp[i - 1] * (i + (i < n - 1))) % MOD;
	}


	for(int i = 1; i < n - 1; i++){
		ans = (ans + ((dp[i - 1] * (n - 1)) % MOD) * (n - 1)) % MOD;
	}
	cout << ans - (n == 1) << endl;
}
