#include<bits/stdc++.h>
#define INF 1000000001
using namespace std;

int main()
{
  int N,M,R;scanf("%d %d %d",&N,&M,&R);
  int r[R];for(int i=0;i<R;i++){scanf("%d ",&r[i]);r[i]--;}
  vector<vector<int>> AB(N,vector<int>(N,INF));
  for(int A,B,C,i=0;i<M;i++)
  {
    scanf("%d %d %d",&A,&B,&C);
    A--;B--;AB[A][B]=C;AB[B][A]=C;
  }
  for(int k=0;k<N;k++)for(int i=0;i<N;i++)for(int j=0;j<N;j++)AB[i][j]=min(AB[i][j],AB[i][k]+AB[k][j]);
  sort(r,r+R);int answer=INF;
  do{
    int ans=0;
    for(int i=1;i<R;i++)ans+=AB[r[i-1]][r[i]];
    answer=min(ans,answer);
  }while(next_permutation(r,r+R));
  printf("%d",answer);
}