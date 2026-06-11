#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
int p(int A,int B){
  if(!B)return 1;
  if(B%2)return p(A,B-1)*A%mod;
  int C=p(A,B/2);
  return C*C%mod;
}
signed main(){
  int N;
  string S;
  cin>>N>>S;
  int A[5100][5100]{};
  A[0][0]=1;
  for(int i=0;i<N;i++){
    for(int j=0;j<=N;j++){
      A[i+1][max(j-1,0LL)]=(A[i+1][max(j-1,0LL)]+A[i][j])%mod;
      A[i+1][j+1]=(A[i+1][j+1]+A[i][j]*2)%mod;
    }
  }
  cout<<A[N][S.size()]*p(p(2,S.size()),mod-2)%mod<<endl;
}