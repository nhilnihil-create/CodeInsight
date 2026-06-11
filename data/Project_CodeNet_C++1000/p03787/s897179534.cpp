#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

int dfs(int i, vector<int> &color, vector<vector<int>> &G){
    int ret = 1;
    for(int j : G[i]){
        if(color[j] == color[i]) ret = 2;
        else if(color[j] == -1){
            color[j] = 1 - color[i];
            ret = max(ret, dfs(j, color, G));
        }
    }
    return ret;
}

int paint(int i, vector<int> &color, vector<vector<int>> &G){
    if(color[i] != -1) return -1;
    color[i] = 0;
    return dfs(i, color, G);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    long long n1 = 0, n2 = 0, n3 = 0;

    vector<int> color(N, -1);
    for(int i=0; i<N; i++){
        if(G[i].empty()) n1++;
        else{
            int p = paint(i, color, G);
            if(p == 1) n2++;
            else if(p == 2) n3++;
        }
    }

    long long ans = n1 * N * 2 - n1 * n1 + n2 * n2 * 2 + n2 * n3 * 2 + n3 * n3;
    cout << ans << endl;

    return 0;
}