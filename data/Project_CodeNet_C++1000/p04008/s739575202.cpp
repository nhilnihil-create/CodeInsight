#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> ch(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(i)
            ch[--a[i]].emplace_back(i);
    }
    i64 ans = (a[0] != 1);
    a[0] = -1;
    // dp[i]: i番目の頂点を根とする部分木の深さの最大値
    // 根でない場合は、これをk-1以内に抑える(0-indexed)
    queue<int> que;
    vector<int> c(n, 0);
    for(auto& x : a)
        if(x != -1)
            ++c[x];
    for(int i = 0; i < n; ++i)
        if(!c[i])
            que.emplace(i);

    vector<int> dp(n, 0);

    while(!que.empty()){
        int x = que.front();
        que.pop();
        if(!x)
            continue;
        if(--c[a[x]] == 0)
            que.emplace(a[x]);
        for(auto& e : ch[x]){
            if(dp[e] + 1 == k)
                ++ans;
            else
                dp[x] = max(dp[x], dp[e] + 1);
        }
    }
    cout << ans << endl;
}
