#include <bits/stdc++.h>
using namespace std;
int main(){
  int INF=pow(10,8);
  int N,M,R;
  scanf("%d%d%d",&N,&M,&R);
  vector<int> rv(R);
  for(int i=0;i<R;i++){
    scanf("%d",&rv[i]);
  }
  vector<vector<int>> D(N,vector<int>(N));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      D[i][j]=INF;
    }
  }
  int A,B,C;
  for(int i=0;i<M;i++){
    scanf("%d%d%d",&A,&B,&C);
    D[A-1][B-1]=min(C,D[A-1][B-1]);
    D[B-1][A-1]=min(C,D[B-1][A-1]);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      for(int k=0;k<N;k++){
        D[j][k]=min(D[j][k],D[j][i]+D[i][k]);
      }
    }
  }
  int roop=1;
  for(int i=1;i<=R;i++){
    roop*=i;
  }
  sort(rv.begin(),rv.end());
  int P=INF;
  int Q;
  for(int i=0;i<roop;i++){
    Q=0;
    for(int j=0;j<R-1;j++){
      Q+=D[rv[j]-1][rv[j+1]-1];
    }
    P=min(P,Q);
    next_permutation(rv.begin(),rv.end());
  }
  printf("%d",P);
}
