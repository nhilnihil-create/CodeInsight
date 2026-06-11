#include<cstdio>
#include<algorithm>
const int N=1e5+5;
int a[N],n,l,t,x,w;
long long cnt=1;
using namespace std;
inline char tc(void)
{
	static char fl[100000],*A=fl,*B=fl;
	return A==B&&(B=(A=fl)+fread(fl,1,100000,stdin),A==B)?EOF:*A++;
}
inline void read(int &x)
{
	x=0; char ch=tc();
	while (ch<'0'||ch>'9') ch=tc();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=tc();
}
inline void write(int x)
{
	if (x/10) write(x/10);
	putchar(x%10+'0');
}
int main()
{
	//freopen("B.in","r",stdin); freopen("B.out","w",stdout);
	register int i;
	read(n); read(l); read(t);
	for (i=1;i<=n;++i)
	{
		read(x); read(w);
		if (w==1) a[i]=(x+t)%l,cnt+=(x+t)/l; else a[i]=(x-t%l+l)%l,cnt-=t%l>x?t/l+1:t/l;
	}
	cnt=(cnt%n+n-1)%n+1;
	sort(a+1,a+n+1);
	for (i=cnt;i<=n;++i)
	write(a[i]),putchar('\n');
	for (i=1;i<cnt;++i)
	write(a[i]),putchar('\n');
	return 0;
}