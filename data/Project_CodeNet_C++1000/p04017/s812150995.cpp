#include<bits/stdc++.h>
#define N 100010
#define swap(a,b) a^=b^=a^=b
using namespace std;
int l,n,m;
int k=2;
int f[N][32]={},a[N]={};
int read(){int s=0,w=1;char ch=getchar();while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();if(ch=='-')w=-1;while(ch<='9'&&ch>='0')s=s*10+ch-'0',ch=getchar();return s*w;}
int main()
{
		n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		l=read();
		for(int i=1;i<=n;++i)
		{
			while(k<=n&&a[k]-a[i]<=l)++k;
			f[i][0]=k-1;
		}
		for(int i=1;i<=30;++i)
			for(int j=1;j<=n;++j)
				f[j][i]=f[f[j][i-1]][i-1];
		m=read();
		for(int i=1;i<=m;++i){
				int x,y;
				int ans=0;
				x=read();y=read();
				if(x>y)swap(x,y);
				for(int j=30;j>=0;--j){
						if(f[x][j]>=y)continue;
						ans+=1<<j,x=f[x][j];
				}
				printf("%d\n",ans+1);
		}
		return 0;
}
