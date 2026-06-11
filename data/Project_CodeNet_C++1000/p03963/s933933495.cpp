#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N,K;
  cin>>N>>K;
  int ans=K*pow(K-1,N-1);
  cout<<ans<<endl;
}