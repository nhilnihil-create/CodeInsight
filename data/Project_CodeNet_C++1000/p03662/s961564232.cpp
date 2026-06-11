#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
#define IN(a,n) rep(i,n){ cin>>a[i]; }
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265
#define F first
#define S second
#define PB push_back
#define int ll


int n;


vector<int> dijkstra(vector<vector<P> >& g,int sp){
  vector<int> dir(n+1,INF);
  dir[sp]=0;
  priority_queue<P,vector<P>,greater<P> > q;
  q.push(P(0,sp));
  while(!q.empty()){
    int d=q.top().F;
    int p=q.top().S; q.pop();
    if(dir[p]!=d) continue;
    rep(i,g[p].size()){
      int np=g[p][i].F;
      int cost=g[p][i].S;
      if(dir[np]>d+cost){
        dir[np]=d+cost;
        q.push(P(dir[np],np));
      }
    }
  }
  return dir;
}



signed main(){

  cin>>n;
  vector<vector<P> > v(n+1);
  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    v[a].PB(P(b,1));
    v[b].PB(P(a,1));
  }

  vector<int> a = dijkstra(v,1);
  vector<int> b = dijkstra(v,n);

  int s=0,t=0;
  FOR(i,1,n+1){
    if(a[i]>b[i]) s++;
    if(a[i]<=b[i]) t++;
  
  }

  if(s<t){
    cout<<"Fennec"<<endl;
  }
  else{
    cout<<"Snuke"<<endl;
  }


}
