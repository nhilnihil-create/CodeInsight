#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N,K;
  cin>>N>>K;
  vector<int> A(N);
  rep(i,N)cin>>A[i];
  sort(rbegin(A),rend(A));
  int mx=0;
  rep(i,K)mx+=A[i];
  cout<<mx<<endl;
  return 0;
}