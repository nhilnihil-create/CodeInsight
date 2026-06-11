#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;

int dfs(int v){
    int res = g[v].size();
    vector<int> a;
    for(auto u : g[v]){
        a.push_back(dfs(u));
    }
    sort(a.rbegin(), a.rend());
    for(int i=0;i<int(a.size());i++){
        res = max(res, a[i]+i+1);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    g.resize(n);
    for(int i=0;i<n-1;i++){
        int p;
        cin >> p;
        p--;
        g[p].push_back(i+1);
    }
    cout << dfs(0) << endl;
    return 0;
}