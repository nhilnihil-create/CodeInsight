#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int N;
  cin>>N;
  vector<ll>vec(N,0);
  cin>>vec[0];
  ll ans=vec[0];
  for(int i=1;i<N;i++){
    cin>>vec[i];
    ans=lcm(ans,vec[i]);
  }
  cout<<ans<<endl;
  return 0;
}
