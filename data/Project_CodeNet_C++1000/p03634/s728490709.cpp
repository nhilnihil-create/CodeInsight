#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<list>
#include<string>
#include<algorithm>
#define ll long long

using namespace std;

struct edge {
  int to;
  ll cost;
};

vector<edge> tree[100010];
ll cost_k[100010];

void dfs(int v,int par,ll dist){
  cost_k[v] = dist;

  for(int i=0;i<(int)tree[v].size();i++){
    if(tree[v][i].to == par) continue;
    dfs(tree[v][i].to, v, dist + tree[v][i].cost);
  }
}

int main(){
  int N;
  cin >> N;

  for(int i=0;i<N-1;i++){
    int a,b,c;
    cin >> a >> b >> c;
    tree[a].push_back({b,c});
    tree[b].push_back({a,c});
  }

  int Q,K;
  cin >> Q >> K;

  dfs(K,-1,0);

  for(int i=0;i<Q;i++){
    int x,y;
    cin >> x >> y;
    cout << cost_k[x] + cost_k[y] << endl;
  }
}