#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B,C,ans=0;
  cin>>A>>B>>C;
  if(A*B*C%2==1){
    ans=min(B*C,min(C*A,A*B));
  }
  cout<<ans<<endl;
}