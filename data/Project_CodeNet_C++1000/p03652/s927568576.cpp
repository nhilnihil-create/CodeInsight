#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=310,M=1000010;
const int inf=0x3f3f3f3f;
inline ll read();
inline void write(ll x);
inline void writeln(ll x);

int n,m,ans=inf;
int a[N][N];
int num[N];
int pos[N];
bool del[N];

inline ll read()
{
	ll s=0;
	bool flag=false;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') flag=true;
	for(;'0'<=ch&&ch<='9';ch=getchar()) s=(s<<3)+(s<<1)+(ch^48);
	if(flag) return -s;
	return s;
}
inline void write(ll x)
{
	if(!x)
	{
		putchar('0'),putchar(' ');
		return ;
	}
	if(x<0) putchar('-'),x=-x;
	char ch[20];
	int tot=0;
	while(x) ch[++tot]=x%10,x/=10;
	for(int i=tot;i;--i) putchar(ch[i]^'0');
	putchar(' ');
}
inline void writeln(ll x)
{
	write(x);
	putchar('\n');
}

int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		pos[i]=1;
		for(int j=1;j<=m;j++) a[i][j]=read();
	}
	bool yes=false;
	while(1)
	{
		for(int i=1;i<=n;i++) num[a[i][pos[i]]]++;
//		for(int i=1;i<=n;i++) write(pos[i]);
//		putchar('\n');
		int maxn=0;
		for(int i=1;i<=m;i++) maxn=max(maxn,num[i]);
		ans=min(ans,maxn);
		for(int i=1;i<=m;i++)
		{
			if(num[i]==maxn) del[i]=true;
			num[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			while(del[a[i][pos[i]]]&&pos[i]<=m) pos[i]++;
			if(pos[i]>m)
			{
				yes=true;
				break;
			}
		}
		if(yes) break;
	}
	printf("%d\n",ans);
	return 0;
}