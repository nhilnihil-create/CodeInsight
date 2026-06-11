//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge {ll from;ll to;ll cost;};

ll V, E, d[1010];
edge es[2010];


bool find_negative_loop() {
    for (ll i = 0; i < V; i++) {
        for (ll j = 0; j < E; j++) {
            edge e = es[j];
            if (d[e.from]!=INF&&d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                if (e.to== V - 1) {
                    return true;
                }
            }
        }
    }
    return false;
}
void shortest_path(ll s){
  rep(i,V)d[i]=INF;
  d[s]=0;
  rep(j,V){
    bool update=false;
    rep(i,E){
      edge e=es[i];
      if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost){
        d[e.to]=d[e.from]+e.cost;
        update=true;
      }
    }
    if(!update)break;
    return;
  }
}
int main(){
  cin>>V>>E;
  rep(i,E){
    ll f,t,c;
    cin>>f>>t>>c;
    es[i].from=f-1;
    es[i].to=t-1;
    es[i].cost=-c;
  }
  shortest_path(0);
  if(find_negative_loop()){
    cout<<"inf"<<endl;
    return 0;
  }
  cout<<-d[V-1]<<endl;
  
}
  
