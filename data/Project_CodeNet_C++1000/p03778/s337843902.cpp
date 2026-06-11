#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N,A,B;
  cin>>N>>A>>B;
  if(A>B)swap(A,B);
  int ans=0;
  if(B-(A+N)>0)ans=B-(A+N);
  cout<<ans<<endl;
  return 0;
}