#include <bits/stdc++.h>
#define ll long long
#define C(i,j) (fac[i] * inv[j] % Mod * inv[(i)-(j)] % Mod)
using namespace std;
const ll N = 10000010;
const ll Mod = 1e9+7;
inline ll read()
{
  ll p=0; ll f=1; char ch=getchar();
  while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();}
  while(ch>='0' && ch<='9'){p=p*10+ch-'0'; ch=getchar();}
  return p*f;
}

ll n,k; ll fac[N],inv[N];

ll f[2010][2010];
void upd(ll &x,ll y){x=(x+y)%Mod;}

int main()
{

  n = read(); k = read();

  fac[0] = 1; for(ll i=1;i<=n*k+n+k;i++) fac[i] = i;
  inv[0] = inv[1] = 1; for(ll i=2;i<=n*k+n+k;i++) inv[i] = (Mod - Mod / i) * inv[Mod%i] % Mod;
  for(ll i=1;i<=n*k+n+k;i++) fac[i] = fac[i-1] * i % Mod,inv[i] = inv[i-1] * inv[i] % Mod;

  f[0][0] = 1; k--; if(!k){printf("1\n"); return 0;}
  for(ll i=0;i<=n;i++)
  {
    for(ll j=i;j<=n;j++)
    {
      if(i) upd(f[i][j] , f[i-1][j]);
      if(j) upd(f[i][j] , f[i][j-1] * C(j*k+i-1,k-1) % Mod);
    }
  }

  return printf("%lld\n",f[n][n] * fac[n] % Mod),0;
}