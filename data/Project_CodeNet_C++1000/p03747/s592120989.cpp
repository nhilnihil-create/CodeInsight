#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll N,L,T;
vector<ll> X;
vector<int> W;

int main(){
  cin>>N>>L>>T;
  vector<ll> place;
  for(int i=0;i<N;i++){
      ll x,w;
      cin>>x>>w;
      X.push_back(x);
      W.push_back(w);
      if(w==1) place.push_back((x+T)%L);
      else place.push_back((x-T+T*L)%L);
  }

  ll count=0;
  for(int i=0;i<N;i++){
      if(W[i]==1){
          count-=(T-(L-X[i])+L)/L;
      }else{
          count+=(T-(X[i]+1)+L)/L;
      }
  }
  count=(count%N+N)%N;

  vector<ll> ans(N); 
  sort(place.begin(),place.end());
  for(int i=0;i<N;i++) ans[(i+count)%N]=place[i];
  for(int i=0;i<N;i++) cout<<ans[i]<<endl;

  return 0;
}
