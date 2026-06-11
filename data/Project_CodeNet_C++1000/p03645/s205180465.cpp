#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int flag = 0;
    for(auto i:g[0]){
        for(auto j:g[i]){
            if(j==n-1) flag = 1; 
        }
    }
    if(flag) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}
