#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 1e5 + 10;
vector<vector<int>> edge(MAX_N, vector<int>{});
vector<int> visited(MAX_N, 0);
vector<int> path{};

bool dfs(int n){
    visited[n] = 1;
    path.push_back(n);
    for(int i=0; i<(int)edge[n].size(); i++){
        if(visited[edge[n][i]] == 0){
            dfs(edge[n][i]);
            break;
        }
    }
    return true;
}

int main(){
    int n, m; cin >> n >> m;
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b; a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(0);
    reverse(path.begin(), path.end());
    path.pop_back();
    visited[0] = 0;
    dfs(0);
    cout << (int)path.size() << endl;
    for(auto& v:path){
        cout << v + 1 << " ";
    }
    cout << endl;
    return 0;
}