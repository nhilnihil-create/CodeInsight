#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, n) g[i].resize(n);
    rep(i, m){
        int a, b; cin >> a >> b; a--; b--;
        g[a][b] ++; g[b][a] ++;
    }
    rep(i, n){
        int cnt = 0;
        for (auto gi:g[i]){
            if (gi != 0) cnt += gi;
        }
        cout << cnt << endl;
    }
}