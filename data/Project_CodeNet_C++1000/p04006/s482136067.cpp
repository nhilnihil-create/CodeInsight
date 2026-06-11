#include<bits/stdc++.h>

int data[2005],dp[2005][2005];

int main()
{
  int n,x;
  long long ans=LLONG_MAX;

  scanf("%d%d",&n,&x);
  for(int c=0;c<n;c++)
    scanf("%d",&data[c]),dp[0][c]=data[c];
  for(int c=1;c<n;c++)
  for(int c2=0;c2<n;c2++)
  {
    dp[c][c2]=std::min(dp[c-1][c2],dp[c-1][((c2-1)+n)%n]);
  }
  for(int c=0;c<n;c++)
  {
    long long tmp=(long long)x*c;

    for(int c2=0;c2<n;c2++)tmp+=dp[c][c2];
    ans=std::min(ans,tmp);
  }
  printf("%lld\n",ans);
}
