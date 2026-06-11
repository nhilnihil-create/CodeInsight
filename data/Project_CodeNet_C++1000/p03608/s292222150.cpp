#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,M,R;
  cin>>N>>M>>R;
  vector<int> B(R);
  for(int &i:B){
    cin>>i;
    i--;
  }
  sort(B.begin(),B.end());
  vector<vector<int>> A(N,vector<int>(N,100000000000000));
  for(int i=0;i<M;i++){
    int a,b,c;
    cin>>a>>b>>c;
    A[a-1][b-1]=c;
    A[b-1][a-1]=c;
  }
  for(int k=0;k<N;k++)
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
  int ans=1000000000000000000;
  do{
    int cnt=0;
    for(int i=1;i<R;i++)
      cnt+=A[B[i-1]][B[i]];
    ans=min(ans,cnt);
  }while(next_permutation(B.begin(),B.end()));
  cout<<ans<<endl;
}