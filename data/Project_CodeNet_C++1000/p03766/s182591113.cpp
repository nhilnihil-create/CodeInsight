#include<bits/stdc++.h>
#define ll long long
const int N = 1000000 + 10;
const int mod = 1e9 + 7;
using namespace std;

ll f[N], s[N];
int n;
int main()
{
  scanf("%d",&n);
  f[1]=n; f[2]=1ll*n*n%mod; 
  s[1]=f[1]; s[2]=(f[1]+f[2])%mod;
  for(int i=3; i<=n; ++i)
  {
    f[i] = f[i-1];
	f[i] += s[i-3];
	f[i] %= mod;
	f[i] += 1ll*(n-1)*(n-1)%mod;
	f[i] += n-i+2;
	f[i] %= mod;
	s[i] = s[i-1]+f[i];
    s[i] %= mod;
  }
  printf("%lld\n",f[n]);




}
