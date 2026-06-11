#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

using Graph = vector<vector<int>>;

int dfs(int root, const Graph &graph){
    if(graph[root].size() == 0)return 0;
    vector<int> v;
    for(auto to: graph[root]){
        int tmp = dfs(to, graph);
        v.push_back(tmp);
    }
    sort(v.rbegin(), v.rend());
    int maxi = 0;
    for(int i=0;i<v.size();++i){
        maxi = max(maxi, v[i]+i+1);
    }
    return maxi;
}

int main(){
    int n;
    cin >> n;
    Graph graph(n, vector<int>());
    for(int i=1;i<n;++i){
        int a;
        cin >> a;
        graph[a-1].push_back(i);
    }

    cout << dfs(0, graph) << endl;

    return 0;
}