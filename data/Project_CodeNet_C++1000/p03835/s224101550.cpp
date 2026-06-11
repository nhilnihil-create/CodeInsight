#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<=N;i++)

signed main(){
  int K,S;
  cin>>K>>S;
  int ans=0;
  rep(x,K){
    rep(y,K){
      int z=S-x-y;
      if(0<=z&&z<=K)ans+=1;
    }
  }
  cout<<ans<<endl;
  return 0;
}