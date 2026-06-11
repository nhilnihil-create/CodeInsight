#include<bits/stdc++.h>
#define ll long long
#define rint register int
using namespace std;
const int N=200001;
int n,f[N][21],g[N][21],a[N],Log[N];
ll ans=0;
inline int read()
{
	int s=0; char ch;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s; 
}
int ask1(int l,int r)//区间[l,r]的最小值
{
  	int k=Log[r-l+1];
  	if(f[l][k]<f[r-(1<<k)+1][k])
  	  return f[l][k];
  	return f[r-(1<<k)+1][k];
} 
int ask2(int l,int r)//区间[l,r]的最小值的位置 
{
	int k=Log[r-l+1];
	if(f[l][k]<f[r-(1<<k)+1][k])
	  return g[l][k];
	return  g[r-(1<<k)+1][k];
} 
inline void solve(int l,int r)
{
  	if(r<l) return;
  	if(l<0||r<0) return;
	int mid=ask2(l,r);  ;
  	solve(l,mid-1),solve(mid+1,r);
  	ans+=(ll)(mid-l+1)*(r-mid+1)*ask1(l,r);
  	
} 
int main()
{
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
  n=read(); Log[1]=0; 
  for(int i=2;i<=200000;i++)
    Log[i]=Log[i>>1]+1;  
  for(int i=1;i<=n;i++) a[i]=read(),f[i][0]=a[i],g[i][0]=i;
  for(int i=1;i<=Log[n]+1;i++)
    for(int j=1;j+(1<<i)-1<=n;j++)
      {
        if(f[j][i-1]<f[j+(1<<(i-1))][i-1])
        {
        	f[j][i]=f[j][i-1];
        	g[j][i]=g[j][i-1];
		}
		else f[j][i]=f[j+(1<<(i-1))][i-1],g[j][i]=g[j+(1<<(i-1))][i-1];
	  }
  solve(1,n);
  printf("%lld\n",ans);
  return 0;
}
