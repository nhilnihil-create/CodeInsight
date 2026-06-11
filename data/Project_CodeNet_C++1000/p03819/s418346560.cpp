#include <cstdio>
#include <cstring>
#include <algorithm>
#define R register
using namespace std;
const int MAXN=300100;
const int MAXM=100100;
int sum[MAXM],n;

template<class T>void read(T &x)
{
	x=0;int ff=0;char ch=getchar();
	while(ch<'0'||ch>'9'){ff|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=ff?-x:x;
}

struct seqs
{
	int l,r,d;
	bool operator<(const seqs& aa)const
	{return d<aa.d;}
}seq[MAXN];

int lowbit(int x)
{return x&(-x);}

void change(int x,int pos)
{
	while(pos<=n)
	{
		sum[pos]+=x;
		pos+=lowbit(pos);
	}
}

int getsum(int pos)
{
	int ans=0;
	while(pos)
	{
		ans+=sum[pos];
		pos-=lowbit(pos);
	}
	return ans;
}

int main()
{
	int m;
	read(m),read(n);
	for(R int i=1;i<=m;++i)
	{
		read(seq[i].l),read(seq[i].r);
		seq[i].d=seq[i].r-seq[i].l+1;
	}
	sort(seq+1,seq+1+m);
	int now=1;
	for(R int i=1;i<=n;++i)
	{
		int ans=0;
		while(now<=m&&seq[now].d<i)
		{
			change(1,seq[now].l);
			change(-1,seq[now].r+1);
			++now;
		}
		for(R int j=0;j<=n;j+=i)
		  ans+=getsum(j);
		ans+=m-now+1;
		printf("%d\n",ans);
	}
	return 0;
}