#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int X,A,B;
  cin>>X>>A>>B;
  string ans="dangerous";
  if(B-A<=X)ans="safe";
  if(A-B>=0)ans="delicious";
  cout<<ans<<endl;
  return 0;
}