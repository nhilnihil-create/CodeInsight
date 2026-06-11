#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr first
#define sc second
using namespace std;

const int mnx = 1e6 + 9;
const int mod =  1e9 + 7;

ll n, m, q, cl[mnx], v[mnx], d[mnx], c[mnx], r[mnx];
vector<int> g[mnx];

void funk(int v, int d, int c){
    if(d < 0) return;
    if(cl[v] == 0) cl[v] = c;
    if(r[v] < d){
        r[v] = d;
        for(int to : g[v]){
            funk(to, d - 1, c);
        }
    }
}

int main(){

cin >> n >> m;

for(int i = 0, v, u; i < m; i++){
    cin >> v >> u;
    g[v].pb(u);
    g[u].pb(v);
}

cin >> q;

for(int i = 1; i <= q; i++){
    cin >> v[i] >> d[i] >> c[i];
}

for(int i = q; i >= 1; --i){
    funk(v[i], d[i], c[i]);
    r[v[i]] = d[i];
}

for(int i = 1; i <= n; i++){
    cout << cl[i] << '\n';
}

return 0;

}
