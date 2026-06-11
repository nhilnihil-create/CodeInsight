#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()

int dfs(int now, vector<vector<int>>& graph)
{
    int i;
    vector<int> v;
    for(i = 0;i < graph.at(now).size();++i){
        v.push_back(dfs(graph.at(now).at(i), graph));
    }
    sort(all(v));
    int res = 0;
    for(i = 0;i < v.size();++i){
        res = max(res, v.at(i) + (int)v.size() - i);
    }
    return res;
}

int main()
{
    int i,j;
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for(i = 1;i < n;++i){
        int a;
        cin >> a;
        --a;
        graph.at(a).push_back(i);
    }
    cout << dfs(0, graph) << endl;

    return 0;
}