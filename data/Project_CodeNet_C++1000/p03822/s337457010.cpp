#include <bits/stdc++.h>
using namespace std;

vector<int> depth;
vector<vector<int>> graph;

void DFS(int v, int parent_v, int d){
    depth[v] = d;
    for(int child_v : graph[v]){
        if(child_v == parent_v) continue;

        DFS(child_v, v, d+1);
    }
}

vector<int> ans;

int DFS2(int v, int parent_v){
    priority_queue<int> pq;
    for(int child_v : graph[v]){
        if(child_v == parent_v) continue;

        pq.push(DFS2(child_v,v));
    }

    if(pq.empty() == true) return ans[v] = 0;

    int count = 1;
    while(pq.empty() == false){
        int x = pq.top(); pq.pop();
        ans[v] = max(ans[v], x + count);
        count += 1;
    }
    return ans[v];
}


int main(){
    int n;
    cin >> n;

    graph.resize(n);
    for(int i=1; i<n; i++){
        int a;
        cin >> a;
        a -= 1;
        
        graph[a].push_back(i);
    }

    depth.resize(n);
    DFS(0, -1, 0);


    ans.assign(n,0);
    DFS2(0,-1);

    /*
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    */
    cout << ans[0] << endl;
    return 0;
}