#include <bits/stdc++.h>
typedef long long ll;
#define LINF 1e18
using namespace std;
struct Edge{
    ll from, to, cost;
};
 
using Edges = vector<Edge>;
 
bool bellman_ford(Edges &Es, int V, int s, vector<ll>& dis){
    dis.resize(V,LINF);
    dis[s] = 0;
    int cnt = 0;
    ll t_num;
    while(cnt < 2*V){
        bool end = true;
        for(auto e: Es){
            if(dis[e.from] != LINF && dis[e.from]+e.cost < dis[e.to]){
                dis[e.to] = dis[e.from] + e.cost;
                end = false;
            }
        }
        if(end) return false;
        if(cnt==V-1) t_num = dis[V-1];
        cnt++;
    }
    return (t_num!=dis[V-1]);
}
int main() {
  int a,b,c,N,M;
  cin >> N >> M;
  Edges E(M);
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    E[i] = {--a,--b,-c};
  }
  vector<ll> dis;
  if (bellman_ford(E,N,0,dis)) {
    cout << "inf";
  } else {
    cout << -dis.back();
  }
}