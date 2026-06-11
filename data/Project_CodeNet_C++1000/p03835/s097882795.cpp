#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
  int K,S;cin>>K>>S;
  int ans=0;
  
  rep(X,K+1){
    rep(Y,K+1){
      int Z=S-X-Y;
      if(0<=Z && Z<=K) ans++;
    }
  }
  cout<<ans<<endl;
}