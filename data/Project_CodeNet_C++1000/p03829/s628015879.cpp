#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007

int main(){
  ll N,A,B;
  cin>>N>>A>>B;
  vector<ll> X(N);
  for(int i=0;i<N;i++){
    cin>>X.at(i);
  }

  ll ans=0;
  for(int i=1;i<N;i++){
    ans+=min(B,A*(X.at(i)-X.at(i-1)));
  }
  cout<<ans<<endl;
}
