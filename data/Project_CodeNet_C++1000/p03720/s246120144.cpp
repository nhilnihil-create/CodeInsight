#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N,M;scanf("%d %d",&N,&M);
  int count[N+1]={};
  for(int a,b,i=0;i<M;i++)
  {
    scanf("%d %d",&a,&b);
    count[a]++;count[b]++;
  }
  for(int i=1;i<N+1;i++)printf("%d\n",count[i]);
}