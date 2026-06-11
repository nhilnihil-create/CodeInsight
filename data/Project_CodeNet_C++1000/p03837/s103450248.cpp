#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)
const int INF = 2147483647;

#define MAX_E 1001
#define MAX_V 100

struct edge{
    int to, cost;
    bool f;
};
typedef pair<int, int> P;

int V,E;
vector<edge> G[MAX_V];
int d[MAX_V];
int preV[MAX_V];

void input_graph(){
    int s,t,c;
    REP(i,E){
        cin>>s>>t>>c;s--;t--;
        G[s].push_back({t,c,false});
        G[t].push_back({s,c,false});
    }
}

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d+V, INF);
    d[s]=0;
    que.push(P(0,s));

    while(!que.empty()){
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        REP(i,G[v].size()){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                preV[e.to]=v;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(){
  cin>>V>>E;
  input_graph();
  REP(i,V){
    REP(j,V) preV[j]=-1;
    dijkstra(i);
    REP(j,V){
      int pre=preV[j],next=j;
      while(pre!=-1){
        REP(k,G[pre].size()) if(G[pre][k].to==next) G[pre][k].f=1;
        REP(k,G[next].size()) if(G[next][k].to==pre) G[next][k].f=1;
        next=pre;
        pre=preV[pre];
      }
    }    
  }
  int ans=E*2;
  REP(i,V) REP(j,G[i].size()) if(G[i][j].f) ans--;
  cout<<ans/2;
}