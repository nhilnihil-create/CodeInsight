#include "bits/stdc++.h"

using namespace std;

const int MOD=1000000007;

/*inline int power(int x,int n,int M) {
	int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (!(n&1)) tmp = ((long long int)tmp*tmp) % M;
		else tmp = ((((long long int)tmp*tmp) % M)*x) % M;
	}
	return tmp;
}*/

inline int power(int x,int n,int M){
  int ret=1;
  int box=x;
  while(n){
    if(n&1)ret=((long long int)ret*box)%M;
    box=((long long int)box*box)%M;
    n>>=1;
  }
  return ret;
}

int main(){
  int N,M;
  cin>>N>>M;
  if(M==1){
    cout<<1<<endl;
    return 0;
  }
  vector<int>by(N*M+1,1);
  vector<int>rev_by(N*M+1,1);
  for(int i=1;i<=N*M;i++){
    by[i]=(1LL*by[i-1]*i)%MOD;
    rev_by[i]=power(by[i],MOD-2,MOD);
  }
  vector<vector<int>>dp(N+1,vector<int>(N+1));
  dp[0][0]=1;
  for(int i=0;i<=N;i++){
    for(int j=i;j<=N;j++){
      if(i)dp[i][j]=dp[i-1][j];
      if(j){
        int add=((long long int)dp[i][j-1]*rev_by[M-2])%MOD;
        add=((long long int)add*by[i+j*(M-1)-1])%MOD;
        add=((long long int)add*rev_by[i+j*(M-1)-1-(M-2)])%MOD;
        dp[i][j]+=add;
        dp[i][j]%=MOD;
      }
    }
  }
  cout<<((long long int)dp.back().back()*by[N])%MOD<<endl;
}