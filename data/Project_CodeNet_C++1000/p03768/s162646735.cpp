#include <bits/stdc++.h>
using namespace std;

struct query{ int v, d, c; };
vector<vector<int>> graph;
vector<vector<bool>> check;
vector<int> ans;

void DFS(int v, int d, int c){
    if(d < 0 || check[d][v] == true) return ;

    if(d == 0) ans[v] = c;
    check[d][v] = true;

    DFS(v, d-1, c);
    for(int adjacent_v : graph[v]){
        DFS(adjacent_v, d-1, c);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int q;
    cin >> q;

    vector<query> qs(q);
    for(int i=0; i<q; i++){
        cin >> qs[i].v >> qs[i].d >> qs[i].c;
        qs[i].v -= 1;
    }
    reverse(qs.begin(),qs.end());

    check.resize(11, vector<bool>(n));
    ans.resize(n);
    for(int i=0; i<q; i++){
        DFS(qs[i].v, qs[i].d, qs[i].c);
    }
    for(int i=0; i<n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}