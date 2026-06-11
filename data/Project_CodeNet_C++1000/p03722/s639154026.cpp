#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (1LL<<60)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
typedef unsigned long long int ull;
typedef long long lint;

struct edge{lint from,to,cost;};
edge es[200000]; // MAX_E
lint d[200000]; // MAX_V
int V,E;
int roop=0;
bool check=true;
lint save;

void bellmanford(int S){
  fill(d,d+V,LINF);
  d[S]=0;
  while(true){
    bool update=false;
    rep(i,E){
      edge e=es[i];
      if(d[e.from]!=LINF && d[e.to]>d[e.from]+e.cost){
        d[e.to]=d[e.from]+e.cost;
        update=true;
      }
    }
    if(!update) break;
    roop++;
    if(roop==V-1) save=d[V-1];
    if(roop==2*V){
      if(save!=d[V-1]) check=false;
      break;
    }
  }
}

int main(void){
  cin >> V >> E;
  rep(i,E){
    edge in;
    cin >> in.from >> in.to >> in.cost;
    in.cost*=-1;
    in.from--,in.to--;
    es[i]=in;
  }
  bellmanford(0);
  if(check) cout << d[V-1]*-1 << endl;
  else cout << "inf" << endl;
}