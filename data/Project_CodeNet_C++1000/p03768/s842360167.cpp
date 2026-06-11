#include <bits/stdc++.h>
using namespace std;
#define finish(x){cout << x << endl; exit(0);}
#define ll long long

const int N = 100001;

int n, m, q, col[N], vis[N][11];
vector <int> v[N];

void go(int node, int d, int c){
    if(d < 0) return;
    if(vis[node][d]) return;
    vis[node][d] = 1;
    if(col[node] == 0) col[node] = c;
    for(auto &i : v[node]){
        go(i, d - 1, c);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin >> q;
    vector <int> v(q), d(q), c(q);
    for(int i = 0 ; i < q ; i++){
        cin >> v[i] >> d[i] >> c[i];
    }
    for(int i = q - 1 ; i >= 0 ; i--){
        go(v[i], d[i], c[i]);
    }
    for(int i = 1 ; i <= n ; i++){
        cout << col[i] << "\n";
    }
}
