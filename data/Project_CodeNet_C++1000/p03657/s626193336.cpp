#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B;
  cin>>A>>B;
  string ans="Impossible";
  if(A%3==0||B%3==0||(A+B)%3==0)ans="Possible";
  cout<<ans<<endl;
  return 0;
}