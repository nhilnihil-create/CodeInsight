#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007

int main(){
  int N;
  cin>>N;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }

  ll sum=0;
  ll ans=0;
  for(int i=0;i<N;i++){
    if(A.at(i)==0){
      ans+=sum/2;
      sum=0;
    }else{
      sum+=A.at(i);
    }
  }
  ans+=sum/2;
  cout<<ans<<endl;
}
