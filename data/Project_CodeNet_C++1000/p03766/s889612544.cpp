#include<bits/stdc++.h>
#define FL "a"
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e6+10;
inline ll read(){
  ll d=0,w=1;char ch=getchar();
  while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
  if(ch=='-')w=-1,ch=getchar();
  while(ch<='9'&&ch>='0')d=d*10+ch-48,ch=getchar();
  return d*w;
}
inline void file(){
  freopen(FL".in","r",stdin);
  freopen(FL".out","w",stdout);
}

inline void upd(int &a,int b){a+=b;if(a>=mod)a-=mod;}
inline void dec(int &a,int b){a-=b;if(a<0)a+=mod;}

inline int poww(int a,int b){
  int res=1;
  for(;b;b>>=1,a=1ll*a*a%mod)
    if(b&1)res=1ll*res*a%mod;
  return res;
}

int n,f[N],g[N],ans;

int main()
{
  n=read();f[0]=g[0]=1;
  for(int i=1;i<=n;i++){
    f[i]=f[i-1];
    if(i>=3)upd(f[i],g[i-3]);
    upd(g[i]=f[i],g[i-1]);
  }
  upd(ans,f[n]);
  for(int i=n-2;~i;i--)
    upd(ans,1ll*f[i]*(i+1)%mod);
  upd(ans,1ll*f[n-1]*(n-1)%mod);
  for(int i=n-2;~i;i--)
    upd(ans,1ll*f[i]*(n-1)%mod*(n-1)%mod);
  printf("%d\n",ans);
  return 0;
}
