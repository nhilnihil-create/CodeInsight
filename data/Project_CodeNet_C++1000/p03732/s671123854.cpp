#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);i++)
vector<int> v[3],ttl[3];

int main(){
  int N,W,w1,v1;
  ll ans=0;
  cin>>N>>W>>w1>>v1;
  v[0].emplace_back(v1);
  for(int i=2;i<=N;i++){
    int wt,vt;
    cin>>wt>>vt;
    wt-=w1;
    v[wt].emplace_back(vt);
  }
  REP(i,4) if(v[i].size()>0) sort(v[i].rbegin(),v[i].rend());

  REP(i,4){
    ttl[i].emplace_back(0);
    REP(j,v[i].size()){
      ttl[i].emplace_back(ttl[i].at(j)+v[i].at(j));
    }
  }

  REP(i,ttl[0].size()){
    REP(j,ttl[1].size()){
      REP(k,ttl[2].size()){
        REP(l,ttl[3].size()){
          ll wght=(ll)w1*(ll)(i+j+k+l)+(ll)(j+2*k+3*l);
          if(wght<=(ll)W){
            ans=max(ans,(ll)ttl[0].at(i)+(ll)ttl[1].at(j)+(ll)ttl[2].at(k)+(ll)ttl[3].at(l));
          }
        }
      }
    }
  }

  cout<<ans;
}