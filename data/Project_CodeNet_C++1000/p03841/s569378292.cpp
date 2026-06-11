#include<bits/stdc++.h>
using namespace std;
#define re register
#define in re int
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define rr read()
#define il inline
#define wr putchar('\n')
#define bl putchar(' ')
il int read()
{
	re char ch;re bool f=1;while((ch=getchar())<'0'||ch>'9')(ch=='-')&&(f=0);
	in x=ch^'0';while((ch=getchar())>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^'0');
	return f?x:-x;
}
il void print(in x)
{
	if(x<0)x=-x,putchar('-');
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
#define mm 250001
int ma[mm],cnt[501],X[501],c[501],pos[501][501];
il bool cmp(const in &x,const in &y){return X[x]<X[y];}
signed main()
{
	in n=rr,m=n*n;
	for(in i=1;i<=n;++i)ma[X[i]=rr]=i,c[i]=i,cnt[i]=i-1;
	sort(c+1,c+1+n,cmp);
	for(in i=1;i<=m;++i)
	{
		if(ma[i])continue;
		for(in j=1;j<=n;++j)
			if(cnt[c[j]])
			{
				ma[i]=c[j];
				--cnt[c[j]];
				break;
			}
	}
	for(in i=1;i<=n;++i)cnt[i]=n-i;
	for(in i=m;i>0;--i)
	{
		if(ma[i])continue;
		for(in j=n;j>0;--j)
			if(cnt[c[j]])
			{
				ma[i]=c[j];
				--cnt[c[j]];
				break;
			}
	}
	for(in i=1;i<=m;++i)pos[ma[i]][++cnt[ma[i]]]=i;
	for(in i=1;i<=n;++i)
		if(pos[i][i]!=X[i])
		{
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
	for(in i=1;i<=m;++i)print(ma[i]),bl;
	wr;
	return 0;
}