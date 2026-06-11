#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  int T[N];int sum=0;
  for(int i=0;i<N;i++){scanf("%d ",&T[i]);sum+=T[i];}
  int M;scanf("%d",&M);
  int P[M],X[M];
  for(int i=0;i<M;i++){scanf("%d %d",&P[i],&X[i]);int s=sum-T[P[i]-1]+X[i];printf("%d\n",s);}
}