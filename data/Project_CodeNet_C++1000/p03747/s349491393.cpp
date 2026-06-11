#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

int N;
ll L,T;
ll X[101010],W[101010],ans[101010];

int main(){
  cin>>N>>L>>T;
  int id=-1;
  L*=2;
  T*=2;
  rep(i,N){
    cin>>X[i]>>W[i];
    X[i]*=2;
    if(W[i]==1&&id==-1) id=i;
  }
  if(id==-1){
    rep(i,N){
      X[i]=((X[i]-T)%L+L)%L;
      cout<<X[i]/2<<endl;
    }
    return 0;
  }
  vector<ll> V(N);
  rep(i,N){
    if(W[i]==1) V[i]=(X[i]+T)%L;
    else V[i]=((X[i]-T)%L+L)%L;
  }
  sort(V.begin(),V.end());

  ll hit=0;
  rep(i,N) if(W[i]==2){
    ll dif=(i>id)?(X[i]-X[id]):(L+X[i]-X[id]);
    ll TT=T;
    if(dif/2<=TT){
      hit++;
      TT-=dif/2;
    }
    hit+=TT/(L/2);
  }
  ll tid=(id+hit)%N;
  ll TX=(X[id]+T)%L;
  for(int i=N-1;i>=0;i--) if(V[i]==TX){
    rep(j,N){
      ans[(tid+j)%N]=V[(i+j)%N]/2;
    }
    break;
  }
  rep(i,N) cout<<ans[i]<<endl;
  return 0;
}
