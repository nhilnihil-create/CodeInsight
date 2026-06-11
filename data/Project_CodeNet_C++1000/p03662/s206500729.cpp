#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define MOD 1000000007

struct edge {int to, cost;};
typedef pair<int, int> P; // firstは最短距離, secondは頂点の番号

#define INF INT_MAX
const int MAX_V=100000;
int V;
vector<edge> G[MAX_V];
int d[MAX_V];
int pre[MAX_V];
int used[MAX_V];
int fe=0,su=0;
bool visited[MAX_V]={};

void dijkstra(int s){
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d+V, INF);
  fill(pre,pre+V,-1);
  d[s]=0;
  que.push(P(0, s));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second; // 頂点の番号
    if (d[v] < p.first) continue;
    for(int i=0;i<G[v].size();i++){
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        pre[e.to]=v;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

vector<int> get_path(int t){
  // s to t;
  vector<int> path;
  for(;t!=-1;t=pre[t]) path.push_back(t);
  reverse(path.begin(),path.end());
  return path;
}

void dfs(int s, int color){
  visited[s]=1;
  for(int i=0;i<G[s].size();i++){
    int ind=G[s][i].to;
    if(used[ind]==0){
      used[ind]=color;
      if(color==1) fe++;
      else su++;
    }
    if(used[ind]==color&&(!visited[ind])) dfs(ind,color);
  }
}

int main(){
  cin>>V;
  for(int i=0;i<V-1;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    G[a].push_back({b,1});
    G[b].push_back({a,1});
  }
  dijkstra(0);
  vector<int> path=get_path(V-1);
  used[0]=1, used[V-1]=2;
  fe++, su++;
  for(int i=1;i<V-1;i++) used[i]=0;
  int ind=path.size()-2;
  for(int i=1;i<=d[V-1]/2;i++){
    if(used[path[i]]==0){
      used[path[i]]=1;
      fe++;
    }else{
      break;
    }
    if(used[path[ind]]==0){
      used[path[ind]]=2;
      su++;
      ind--;
    }else{
      break;
    }
  }
  dfs(0, 1);
  dfs(V-1, 2);
  //for(int i=0;i<V;i++) cout<<used[i]<<endl;
  if(fe>su) cout<<"Fennec"<<endl;
  else cout<<"Snuke"<<endl;
  return 0;
}