#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N,ans=0;
  cin>>N;
  for(int i=1;i<=N;i++){
    ans+=i;
  }
  cout<<ans<<endl;
  return 0;
}