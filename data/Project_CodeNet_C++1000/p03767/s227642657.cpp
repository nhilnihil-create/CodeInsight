#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N;
  cin>>N;
  vector<int> A(3*N);
  rep(i,3*N)cin>>A[i];
  sort(rbegin(A),rend(A));
  int ans=0;
  int I=0,i=1;
  while(I<N){
    ans+=A[i];
    i+=2;
    I+=1;
  }
  cout<<ans<<endl;
}