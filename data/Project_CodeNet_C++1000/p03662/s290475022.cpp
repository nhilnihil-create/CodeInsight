#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0;i < (n);i++)
#define P pair<int,int>
#define pb push_back
#define mk make_pair
using namespace std;
const int INF = 1e9;

typedef long long ll;

#define MAX_V 100010

struct edge {
    int to;
    int cost;
};


int V;
vector<edge> G[MAX_V];
int d[MAX_V];


void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;

        for (int i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}



int main(){
  int E,r;
  cin >> V;
  E = V-1;
  REP(i,E){
    int f,t,c;
    cin >> f >> t;
    f--;
    t--;
    c = 1;
    edge e = {t,c};
    G[f].pb(e);
    e.to = f;
    G[t].pb(e);
  }
  int dis[2][V];
  dijkstra(0);
  REP(i,V){
    dis[0][i] = d[i];
  }
  dijkstra(V-1);
  REP(i,V){
    dis[1][i] = d[i];
  }
  int black = 0,white = 0;
  REP(i,V){
    //cout << dis[0][i] << "      " << dis[1][i] << endl;
    if(dis[0][i] <= dis[1][i])
      black++;
    else
      white++;
  }
  if(black > white)
    cout << "Fennec" << endl;
  else
    cout << "Snuke" << endl;
  return 0;
}
