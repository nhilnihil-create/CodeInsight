#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B,ans=0;
  cin>>A>>B;
  if(A-B>0)ans=A-B;
  cout<<ans<<endl;
}