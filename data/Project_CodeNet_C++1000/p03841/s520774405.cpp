#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>

#define maxn 505

using namespace std;

inline int getint()
{
	int num=0,flag=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;
	while(c>='0'&&c<='9')num=num*10+c-48,c=getchar();
	return num*flag;
}

int n;
int p[maxn],f[maxn],a[maxn*maxn];
inline bool cmp(int x,int y){return p[x]<p[y];}

int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)p[i]=getint(),f[i]=i;
		sort(f+1,f+n+1,cmp);
		int now=1,flag=0;
		for(int i=1;i<=n;i++)
		{
			a[p[f[i]]]=f[i];
			for(int j=1;j<f[i];j++)
			{
				while(a[now])now++;
				a[now]=f[i];
			}
			if(now>p[f[i]]){puts("No");flag=1;break;}
		}
		if(flag)continue;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n-f[i];j++)
			{
				while(a[now])now++;
				if(now<p[f[i]]){puts("No");flag=1;break;}
				a[now]=f[i];
			}
			if(flag)break;
		}
		if(!flag)
		{
			puts("Yes");
			for(int i=1;i<=n*n;i++)printf("%d%c",a[i],i==n*n?10:32);
		}
	}
}