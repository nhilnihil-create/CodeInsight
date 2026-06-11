#include "bits/stdc++.h"
using namespace std;
#define ff first
#define ss second
vector<vector<pair<int,int>>> dt;
vector<pair<int,int>> Es;
signed main(){
    int n,m,a,b,v,d,c;
    cin >> n >> m;
    dt.resize(n);
    for(auto& x: dt)x.resize(11);
    for(int i = 0; i < m;i++){
        cin >> a >> b;a--;b--;
        Es.push_back({a, b});
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> v >> d >> c;v--;
        dt[v][d] = {i, c};
    }
    for(int d = 10; d > 0; d--){
        for(auto e: Es)
            dt[e.ff][d-1] = max(dt[e.ff][d-1], dt[e.ss][d]),
            dt[e.ss][d-1] = max(dt[e.ss][d-1], dt[e.ff][d]);
        for(auto& x: dt) x[0] = max(x[0], x[d]);
    }
    for(auto& x: dt)cout << x[0].ss << endl;
}
