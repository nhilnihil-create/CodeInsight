#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,a,ma=-50,mi=50;
  cin>>N>>a;
  vector<int> x(N);
  for(int &i:x){
    cin>>i;
    i-=a;
    ma=max(ma,i),mi=min(mi,i);
  }
  if(mi*ma>0){
    cout<<0<<endl;
    return 0;
  }
  mi*=N;
  ma*=N;
  vector<vector<int>> A(N+1,vector<int>(ma-mi+1));
  for(int i=0;i<=ma-mi;i++)
    A[0][i]=0;
  A[0][0-mi]=1;
  for(int j=1;j<=N;j++){
    for(int i=0;i<=ma-mi;i++){
      A[j][i]=A[j-1][i];
      if(ma-mi>=i-x[j-1] && i-x[j-1]>=0){
        A[j][i]+=A[j-1][i-x[j-1]];
      }
    }
  }
  cout<<A[N][0-mi]-1<<endl;
}