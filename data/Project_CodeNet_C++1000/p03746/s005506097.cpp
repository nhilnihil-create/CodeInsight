#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

const int mod=1e9+7;

int main(){
  int n,m;cin>>n>>m;
  int reached[n]={};
  VI G[n];
  int a,b;
  rep(i,m){
    cin>>a>>b;
    G[--a].push_back(--b);
    G[b].push_back(a);
  }
  reached[a]=reached[b]=1;
  VI p;
  p.push_back(a);
  int cur=a;
  while(true){
    bool isC=0;
    for(auto v:G[cur]){
      if(reached[v])continue;
      reached[v]=1;
      isC=1;p.push_back(v);
      cur=v;break;
    }
    if(!isC)break;
  }
  reverse(all(p));
  p.push_back(b);
  cur=b;
  while(true){
    bool isC=0;
    for(auto v:G[cur]){
      if(reached[v])continue;
      reached[v]=1;
      isC=1;p.push_back(v);
      cur=v;break;
    }
    if(!isC)break;
  }
  cout<<(int)p.size()<<endl;
  rep(i,p.size()){
    cout<<p[i]+1<<endl;
  }
}
