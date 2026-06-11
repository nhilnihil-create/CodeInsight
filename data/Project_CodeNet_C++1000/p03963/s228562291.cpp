#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N,K;scanf("%d %d",&N,&K);
  long long ans=K;N--;
  ans*=pow(K-1,N);
  printf("%lld\n",ans);
}