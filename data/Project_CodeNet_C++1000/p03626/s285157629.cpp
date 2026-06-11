#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MAX 1000010
#define MOD 1000000007
  
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
  int N; cin>>N;
  string S,T; cin>>S;
  cin>>T;
  vector<ll> dp(N);
  if(N==1){
    cout<<3<<endl;
    return 0;
  }else if(N==2){
    cout<<6<<endl;
    return 0;
  }

  if(S.at(0)==T.at(0))dp.at(0) = 3;
  else dp.at(0) = 6;
  rep1(i,N){
    if(S.at(i)==T.at(i)){
      if(S.at(i-1)==T.at(i-1))dp.at(i)=dp.at(i-1)*2;
      else dp.at(i)=dp.at(i-1);
    }else if(S.at(i)==S.at(i-1)){
      dp.at(i)=dp.at(i-1);
    }else if(S.at(i-1)!=T.at(i-1)){
      dp.at(i)=dp.at(i-1)*3;
    }else dp.at(i)=dp.at(i-1)*2;
    
  }
  //rep(i,N)cout<<dp.at(i)<<endl;
  cout<<dp.at(N-1)%MOD<<endl;
}