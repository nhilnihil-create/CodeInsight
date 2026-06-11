#include<bits/stdc++.h>
using namespace std;

#define dd ch=getchar()
inline int read()
{
	int x=0;bool f=false;char dd;
	while(!isdigit(ch))f|=ch=='-',dd;
	while(isdigit(ch))x=(x<<1)+(x<<3)+ch-48,dd;
	return f?-x:x;
}
#undef dd
void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
#define writeln(x) (write(x),putchar('\n'))
#define writesp(x) (write(x),putchar(' '))

const int N=2e5+5,INF=0x3f3f3f3f;
bool a[N];
int val[N],n,midid;
inline int dis(int x){return abs(midid-x);}
inline bool check(int k)
{
	bool f0=true,f1=true;
	for(int i=1;i<=n;i++)
	{
		a[i]=(val[i]>=k);
		if(i&1)f0&=a[i]^1,f1&=a[i];
		else f0&=a[i],f1&=a[i]^1;
	}
	if(f0)return false;
	if(f1)return true;
	int minn[2]={INF,INF};
	for(int i=2;i<=n;i++)
		if(a[i]==a[i-1])
			minn[a[i]]=min(minn[a[i]],min(dis(i),dis(i-1)));
	return minn[1]<minn[0];
}
int main()
{
	n=(midid=read())*2-1;
	for(int i=1;i<=n;i++)
		val[i]=read();
	int l=0,r=INF;
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	write(l);
	return 0;
}