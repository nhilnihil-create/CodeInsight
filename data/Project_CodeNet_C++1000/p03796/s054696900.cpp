#include<bits/stdc++.h>
#define INF 1000000007
using namespace std;

int main()
{
  int N;long long ans=1;scanf("%d",&N);
  for(int i=1;i<N+1;i++){ans*=i;ans%=INF;}
  printf("%lld",ans);
}