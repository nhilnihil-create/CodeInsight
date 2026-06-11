#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N;
  cin>>N;
  int ans=0;
  rep(i,N){
    int A,B;
    cin>>A>>B;
    ans+=B-A+1;
  }
  cout<<ans<<endl;
  return 0;
}