#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 300003
#define MOD 1000000007
#define INF 1000000000000000000
using Graph=vector<vector<int>>;

int main(){
  int N,K;
  cin>>N>>K;
  vector<ll> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }

  vector<ll> plus_sum(N+1,0);
  vector<ll> minus_sum(N+1,0);
  for(int i=0;i<N;i++){
    if(a.at(i)>0){
      plus_sum.at(i+1)+=a.at(i);
    }else{
      minus_sum.at(i+1)+=a.at(i);
    }
    minus_sum.at(i+1)+=minus_sum.at(i);
    plus_sum.at(i+1)+=plus_sum.at(i);
  }

  ll ans=0;
  for(int i=0;i<N-K+1;i++){
    ans=max<ll>(ans,plus_sum.at(N)+minus_sum.at(i+K)-minus_sum.at(i));
    ans=max<ll>(ans,plus_sum.at(i)+plus_sum.at(N)-plus_sum.at(i+K));
  }
  cout<<ans<<endl;
}
