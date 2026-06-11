#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,Ma,Mb;cin >> N >> Ma >> Mb;
  vector<int> A(N);
  vector<int> B(N);
  vector<int> C(N);
  int Amax=0,Bmax=0,Cmax=0;
  for(int i=0;i<N;i++){
    cin >> A[i] >> B[i] >> C[i];
    Amax += A[i];
    Bmax += B[i];
    Cmax += C[i];
  }
  int INF = Cmax + 1;
  vector<vector<vector<int>>> DP(N+1,vector<vector<int>>(Amax+1,vector<int>(Bmax+1,INF)));
  DP[0][0][0]=0;
  for(int i=1;i<=N;i++){
    for(int ca=0;ca<=Amax;ca++){
      for(int cb=0;cb<=Bmax;cb++){
        DP[i][ca][cb] = DP[i-1][ca][cb];
        if(ca>=A[i-1]&&cb>=B[i-1]){
          DP[i][ca][cb]=min(DP[i][ca][cb],DP[i-1][ca-A[i-1]][cb-B[i-1]]+C[i-1]);
        }
      }
    }
  }
  int ans = INF;
  //for(int k=1;k*Ma<=Amax&&k*Mb<=Bmax;k++){
  //  ans = min(ans,DP[N][k*Ma][k*Mb]);
  //}
  for(int ca=1;ca<=Amax;ca++){
    for(int cb=1;cb<=Bmax;cb++){
      //cout << DP[N][ca][cb] << " ";
      if(ca*Mb==Ma*cb){
        ans = min(ans,DP[N][ca][cb]);
      }
    }
    //cout << endl;
  }
  if(INF<=ans){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
}