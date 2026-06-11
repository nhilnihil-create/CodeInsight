#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<N;i++)
int main(){
  int N; cin>>N;
  vector<int>A(N);
  rep(i,N)cin>>A[i];
  int ans=0;
  rep(i,N)if(A[A[i]-1]==i+1)ans++;
  cout<<ans/2<<endl;
}