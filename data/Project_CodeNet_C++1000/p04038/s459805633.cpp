#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<complex>
#include<vector>
#include<cstdio>
#include<string>
#include<bitset>
#include<ctime>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define Cpy(x,y) memcpy(x,y,sizeof(x))
#define Set(x,y) memset(x,y,sizeof(x))
#define FILE "4911"
#define mp make_pair
#define pb push_back
#define RG register
#define il inline
using namespace std;
typedef unsigned long long ull;
typedef vector<int>VI;
typedef long long ll;
typedef double dd;
const int N=5010;
const int M=4e6;
const int base=26;
const dd eps=1e-6;
const int inf=1e9;
const ll INF=1ll<<60;
const ll P=100000;
const int mod=1e9+7;
il ll read(){
  RG ll data=0,w=1;RG char ch=getchar();
  while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
  if(ch=='-')w=-1,ch=getchar();
  while(ch<='9'&&ch>='0')data=data*10+ch-48,ch=getchar();
  return data*w;
}
il void file(){
  srand(time(NULL)+rand());
  freopen(FILE".in","r",stdin);
  freopen(FILE".out","w",stdout);
}

int n,k,fac[4000010],inv[4000010],f[4005][2005];
il void upd(int &a,int b){a+=b;if(a>=mod)a-=mod;}
il int C(int n,int m){
  //printf("%d,%d\n",n,m);
  return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
il int poww(int a,int b){
  RG int ret=1;
  for(;b;b>>=1,a=1ll*a*a%mod)
    if(b&1)ret=1ll*ret*a%mod;
  return ret;
}

int main()
{
  fac[0]=inv[0]=1;
  for(RG int i=1;i<=M;i++)fac[i]=1ll*fac[i-1]*i%mod;
  inv[M]=poww(fac[M],mod-2);
  for(RG int i=M-1;i;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;

  n=read();k=read();f[0][0]=1;if(k==1)return puts("1"),0;
  for(RG int i=1;i<=n;i++)
    for(RG int j=0;j<=i;j++){
      upd(f[i][j],f[i-1][j]);
      if(j)upd(f[i][j],1ll*f[i][j-1]*C(n*k-(j-1)*(k-1)-i-1,k-2)%mod*(n-j+1)%mod);
      //printf("f[%d][%d]=%d\n",i,j,f[i][j]);
    }
  printf("%d\n",f[n][n]);
  return 0;
}
