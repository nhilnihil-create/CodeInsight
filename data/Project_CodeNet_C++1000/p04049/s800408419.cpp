#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 2e3 + 5;
ll dep[N], dp[N], k, cnt = 0;
vector<ll> node[N];
void dfs(ll u, ll p){
        vector<ll> mem;
        if (k % 2 == 1 && dep[u] * 2 >= (k + 1)){
                if (dep[u] * 2 > (k + 1)) cnt++;
                else dp[u] = 1;

        }
        else dp[u] = 0;
        for (auto j : node[u]){
                if (j != p){
                        dep[j] = dep[u] + 1;
                        dfs(j, u);
                        dp[u] += dp[j];
                        if (p == 0) {
                                mem.push_back(dp[j]);
                        }
                }
        }
        if (p == 0 && k % 2 == 1){
                sort(mem.begin(), mem.end(), greater<ll>());
                cnt += dp[u] - mem[0];
        }
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        //freopen("VLJUM.INP", "r", stdin);
        //freopen("VLJUM.OUT", "w", stdout);
        ll n;
        cin >> n >> k;
        for (int i = 1; i <= (n - 1); i++){
                ll u, v;
                cin >> u >> v;
                node[u].push_back(v);
                node[v].push_back(u);
        }
        ll ans = 1e18;
        for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++) {
                        dep[j] = 0;
                        dp[j] = 0;
                }
                cnt = 0;
                dfs(i, 0);
                if (k % 2 == 0){
                        for (int j = 1; j <= n; j++){
                                if (dep[j] * 2 > k) cnt++;
                        }
                }
                ans = min(ans, cnt);
        }
        cout << ans;
}

