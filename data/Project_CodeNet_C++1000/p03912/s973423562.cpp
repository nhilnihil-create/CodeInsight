#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,M;
  cin>>N>>M;
  vector<vector<int>> A(M);
  vector<int> B(100001,0);
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    A[a%M].push_back(a);
    B[a]++;
  }
  int ans=A[0].size()/2;
  for(int i=1;i<(M+1)/2;i++){
    if(A[i].size()>A[M-i].size()){
      ans+=A[M-i].size();
      int cnt=0;
      for(int j=i;j<=100001;j+=M)
        cnt+=B[j]/2;
      ans+=min((int)(A[i].size()-A[M-i].size())/2,cnt);
    }else if(A[i].size()<A[M-i].size()){
      ans+=A[i].size();
      int cnt=0;
      for(int j=M-i;j<=100001;j+=M)
        cnt+=B[j]/2;
      ans+=min((int)(A[M-i].size()-A[i].size())/2,cnt);
    }else if(A[i].size()==A[M-i].size()){
      ans+=A[i].size();
    }
  }
  if(M%2==0)
    ans+=A[M/2].size()/2;
  cout<<ans<<endl;
}