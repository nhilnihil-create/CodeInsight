#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N,K;
  cin>>N>>K;
  int ans=0;
  rep(i,N){
    int X;
    cin>>X;
    if(K-X>X)ans+=X*2;
    else ans+=(K-X)*2;
  }
  cout<<ans<<endl;
  return 0;
}