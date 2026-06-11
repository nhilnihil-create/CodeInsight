#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B,H;
  cin>>A>>B>>H;
  int ans=(A+B)*H/2;
  cout<<ans<<endl;
  return 0;
}