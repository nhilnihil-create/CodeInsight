#include<bits/stdc++.h>
using namespace std;
const int mx = 2e5 + 9;

queue<int>q;
vector<int>adj[mx];
int vis[mx];
int dis[mx];

void bfs(int s){
dis[s] = 0;
vis[s] = 1;
q.push(s);
while(!q.empty()){
    int tmp = q.front();
    q.pop();
    for(auto u : adj[tmp]){
        if(vis[u] == 1) continue;
        vis[u] = 1;
        dis[u] = 1 + dis[tmp];
        q.push(u);
    }
}
}

int main(){
int n , m;
cin>>n>>m;
for(int i=0 ; i<m ; i++){
    int u , v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bfs(1);

/*for(int i=1 ; i<=n ; i++)
    cout<<dis[i]<<" ";
cout<<endl;*/
if(vis[n] && dis[n]==2){
    cout<<"POSSIBLE"<<endl;
}
else
cout<<"IMPOSSIBLE"<<endl;

}
