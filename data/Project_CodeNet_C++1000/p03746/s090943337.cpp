#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for(i=0;i<m;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> ret_f,ret_s;
    ret_f.push_back(0);
    ll now = 0;
    set<ll> st;
    st.insert(0);
    while(1){
        int f=1;
        for(i=0;i<g[now].size();i++){
            if(st.find(g[now][i])==st.end()){
                now = g[now][i];
                ret_f.push_back(now);
                st.insert(now);
                f=0;
                break;
            }
        }
        if(f==1)break;
    }
    int f=1;
    for(i=1;i<g[0].size();i++){
        if(st.find(g[0][i])==st.end()){
            f=0;
            break;
        }
    }
    if(f==1){
        cout << ret_f.size() << endl;
        for(auto &x:ret_f){
            cout << x+1 << " ";
        }
        cout << endl;
        return 0;
    }
    now = 0;
    while(1) {
        int f = 1;
        for(i = 0; i < g[now].size(); i++) {
            if(st.find(g[now][i]) == st.end()) {
                now = g[now][i];
                ret_s.push_back(now);
                st.insert(now);
                f = 0;
                break;
            }
        }
        if(f == 1) break;
    }
    reverse(ret_s.begin(),ret_s.end());
    for(i=0;i<ret_f.size();i++){
        ret_s.push_back(ret_f[i]);
    }
    cout << ret_s.size() << endl;
    for(auto &x : ret_s) {
        cout << x+1 << " ";
    }
    cout << endl;
    return 0;
}