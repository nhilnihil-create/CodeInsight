/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int n;
int a , b;
int vis[N];
int tim[N][2];
vector < int > adj[N];

void bfs(int s , int id){
    queue < int > q;
    q.push(s);
    tim[s][id] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(tim[v][id] == 0){
                tim[v][id] = tim[u][id] + 1;
                if(id == 0 && tim[v][1] <= tim[v][0]){
                    a = v;
                    b = u;
                    return;
                }
                q.push(v);
            }
        }
    }
}

int dfs(int u , int p){
    int ret = 0;
    for(auto v : adj[u]){
        if(v == p || (a == u && b == v) || (a == v && b == u))
            continue;
        ret += dfs(v , u);
    }
    return ret + 1;
}

int main(){
    scanf("%d" , &n);
    for(int i = 1; i < n; i++){
        int u , v;
        scanf("%d%d" , &u , &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1 , 1);
    bfs(n , 0);
    int A = dfs(1 , -1);
    int B = dfs(n , -1);
    cerr << a << " " << b << " " << A << " " << B <<  endl;
    puts( (A <= B) ? "Snuke" : "Fennec");
}


