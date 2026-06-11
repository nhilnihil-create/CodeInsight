/*    三玖天下第一！！！  */
#include<bits/stdc++.h>
using namespace std;
const int ng=30,maxn=1e5;
int n,L,x[maxn+5]={},f[ng+5][maxn+5]={};
inline int dread()
{
	int x=0;bool f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f^=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return f?x:-x;
}
inline void in(){n=dread();for(int i=1;i<=n;i++) x[i]=dread();L=dread();}
inline void work()
{
	for(int i=1;i<=n;i++) f[0][i]=upper_bound(x+i,x+1+n,x[i]+L)-x-1;
	for(int i=1;i<=ng;i++) for(int j=1;j<=n;j++) f[i][j]=f[i-1][f[i-1][j]];
}
inline void out()
{
	for(int q=dread(),a,b,ans;q;q--)
	{
		a=dread();b=dread();ans=0;if(a>b) swap(a,b);
		for(int i=ng;i>=0;i--) if(f[i][a]<b) ans+=(1<<i),a=f[i][a];
		printf("%d\n",ans+1);
	}
}
int main(){in();work();out();return 0;}
