#include <bits/stdc++.h>
#define rhl (1000000007)
int f[5005][5005],n,m,ans;
char s[5005];
int main(){
  std::cin>>n,scanf("%s",s),m=strlen(s),f[0][0]=ans=1;
  for (int i=0;i<n;++i)
    for (int j=0;j<n;++j)
      (f[i+1][std::max(0,j-1)]+=f[i][j])%=rhl,(f[i+1][j+1]+=2LL*f[i][j])%=rhl;
  for (int i=0;i<m;++i) ans=1LL*ans*500000004%rhl;
  std::cout<<1LL*ans*f[n][m]%rhl; return 0;
}
