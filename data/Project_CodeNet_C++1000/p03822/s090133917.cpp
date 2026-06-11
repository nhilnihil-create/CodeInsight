#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> edge;
int dfs(int p){
    if(edge[p].size()==0){
        return 0;
    }
    else{
        int v[edge[p].size()];
        for(int i=0; i<edge[p].size(); i++){
            v[i] = dfs(edge[p][i]);
        }
        sort(v,v+edge[p].size(),greater<int>());
        int ret = -1;
        for(int i=0; i<edge[p].size(); i++){
            ret = max(ret,v[i]+i+1);
        }
        return ret;
    }
}

int main(){
    cin >> n; 
    int a[n];
    for(int i=1; i<n; i++){
        cin >> a[i];
        a[i]--;
    }
    edge.resize(n);
    for(int i=1; i<n; i++){
        edge[a[i]].push_back(i);
    }
    cout << dfs(0) << endl;
    return 0;
}
