#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = j; i >= k; i--)
#define PB push_back
#define MEM(n, val) memset((n), val, sizeof(n))
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define LL long long
#define MOD 998244353
#define MX 200010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

int n;
LL ara[100010];
bool vis[110][110];
//int dp[110][110];
//
//int func(int pos, int nisi) {
//    if(pos == n) {
//        if(nisi) {
//            return -1000000000;
//        }
//        return 0;
//    }
//    if(vis[pos][nisi]) {
//        return dp[pos][nisi];
//    }
//    int ans = -1000000000;
//
////    /// na niye
////    ans = func(pos + 1, nisi);
//
//    /// mn hishebe niye
//    ans = max(ans, ara[pos] + func(pos + 1, nisi + 1));
//
//    /// mx hishebe niye
//    if(nisi) {
//        ans = max(ans, func(pos + 1, nisi - 1));
//    }
//    vis[pos][nisi] = 1;
//    return dp[pos][nisi] = ans;
//}

int main()  {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);tt
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;

    cin >> n;
    n *= 2;
    FOR(i, 0, n - 1) {
        cin >> ara[i];
    }
    sort(ara, ara + n);
//    FOR(i, 0, n - 1) {
//        cout << ara[i] << " ";
//    }
//    cout << "\n";
    LL ans = 0;
//    for(int i = n - 2; i >= 0; i-= 2) {
//        ans += ara[i];
//    }

    for(int i = 0; i < n; i += 2) {
        ans += ara[i];
    }
    cout << ans << "\n";
//    cout << func(0, 0) << "\n";
    return 0;
}
/**
*/
