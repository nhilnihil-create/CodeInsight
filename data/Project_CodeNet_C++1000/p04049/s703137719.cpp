#include <bits/stdc++.h>
using namespace std;

int dist[2005][2005];
vector<int> adjl[2005];
bool disabled[2005];
int n,k;

void dfs(int node, int parent, int s){
for (auto x : adjl[node]){
    if (x==parent) continue;
    dist[s][x] = dist[s][node] + 1;
    dfs(x,node,s);
}
}

int main(){
scanf("%d%d",&n,&k);
for (int x = 0; x<n-1; x++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;b--;
    adjl[a].push_back(b);
    adjl[b].push_back(a);
}
for (int x = 0; x<n; x++){
    dist[x][x] = 0;
    dfs(x,-1,x);
}
int curdist = 0;
int farnode = -1;
for (int x = 0; x<n; x++){
    if (dist[0][x]>curdist){
        curdist = dist[0][x];
        farnode = x;
    }
}
int diameter = 0;
for (int x = 0; x<n; x++){
    diameter = max(diameter,dist[farnode][x]);
}
if (diameter<=k){
    printf("0");
    return 0;
}
vector<pair<int,int> > nodes;
for (int x = 0; x<n; x++){
    nodes.push_back({dist[0][x],x});
}
sort(nodes.begin(),nodes.end(),greater<pair<int,int> > ());
stack<int> nxt;
int ans = 0;
for (int x = 0; x<n; x++){
    if (x!=0 && nodes[x].first<nodes[x-1].first){
        while (!nxt.empty()){
            int t = nxt.top();
            nxt.pop();
            disabled[t] = true;
        }
    }
    int te = 0;
    for (int y = 0; y<n; y++){
        if (disabled[y]) continue;
        if (dist[nodes[x].second][y]<=k){
            te++;
        }
    }
    ans = max(ans,te);
    nxt.push(nodes[x].second);
}
printf("%d",n-ans);
}
