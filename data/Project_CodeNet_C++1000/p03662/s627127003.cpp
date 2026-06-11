#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007LL;
const int INF = LLONG_MAX;

void dfs(int cur, vector<int> &result, vector<vector<int> > &g, int cost){
    result[cur] = cost;
    for(auto nxt : g[cur]){
        if(result[nxt] == -1){
            dfs(nxt, result, g, cost + 1);
        }
    }
}

signed main(){
    
    int n; cin >> n;
    vector<vector<int> > g(n);
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> result_f(n, -1);
    vector<int> result_s(n, -1);
    dfs(0, result_f, g, 0);
    dfs(n - 1, result_s, g, 0);
    int cnt_f = 0;
    int cnt_s = 0;
    for(int i = 0; i < n; i++){
        if(result_f[i] <= result_s[i]) cnt_f++;
        else cnt_s++;
    }

    //cout << cnt_f << " " << cnt_s << endl;

    if(cnt_f > cnt_s) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    return 0;
}