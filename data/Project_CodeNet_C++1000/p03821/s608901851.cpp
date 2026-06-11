#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  cin>>N;
  vector<int> A(N),B(N);
  for(int i=0;i<N;i++)
    cin>>A[i]>>B[i];
  int ans=0;
  for(int i=N-1;i>=0;i--)
    ans+=(A[i]+ans+B[i]-1)/B[i]*B[i]-(A[i]+ans);
  cout<<ans<<endl;
}