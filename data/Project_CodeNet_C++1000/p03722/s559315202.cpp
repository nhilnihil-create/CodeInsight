#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60;
const ll mod=1000003 ;

struct edge{ll from,to,cost;};

edge es[200020],es2[200020];

ll d[200020],d2[200020];
int V,E;
bool flag;

void shortest_path(int s){
  for(int i=0;i<V;i++)d[i]=longinf;
  d[s]=0;
  while(true){
    bool update=false;
    for(int i=0;i<E;i++){
      edge e=es[i];
      if(d[e.from]!=longinf && d[e.to]>d[e.from]+e.cost && d2[e.from]!=longinf && d2[e.to]!=longinf){
        d[e.to]=d[e.from]+e.cost;
        update=true;
      }
    }
    if(!update)break;
  }
}

void shortest_path2(int s){
  for(int i=0;i<V;i++)d2[i]=longinf;
  d2[s]=0;
  while(true){
    bool update=false;
    for(int i=0;i<E;i++){
      edge e=es2[i];
      if(d2[e.from]!=longinf && d2[e.to]>d2[e.from]+e.cost){
        d2[e.to]=d2[e.from]+e.cost;
        update=true;
      }
    }
    if(!update)break;
  }
}

bool find_negative_loop(){
  memset(d,0,sizeof(d));
  rep(i,2*V){
    rep(j,E){
      edge e=es[j];
      if(d2[e.from]<longinf && d2[e.to]<longinf && d[e.to]>d[e.from]+e.cost){
        d[e.to]=d[e.from]+e.cost;
        if(i==2*V-1)return true;
      }
    }
  }
  return false;
}

int main(){
  ll n,m;
  cin >> n >> m;
  ll x[m],y[m],z[m];
  rep(i,m){
    cin >> x[i] >> y[i] >> z[i];
    x[i]--,y[i]--;
    es[i]={x[i],y[i],-z[i]};
    es2[i]={y[i],x[i],1};
  }
  V=n;
  E=m;
//  rep(i,m){
//    cout << es2[i].from << ' ' << es2[i].to << ' ' << es2[i].cost << endl;
//  }
  shortest_path2(n-1);
//  rep(i,V)cout << d2[i] << ' ' << i << endl;
  if(find_negative_loop()){
    cout << "inf" << endl;
    return 0;
  }
  shortest_path(0);
  cout << -d[n-1] << endl;
return 0;}