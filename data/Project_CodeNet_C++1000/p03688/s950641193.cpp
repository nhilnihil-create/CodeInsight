#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N];
bool solve()
{
	int n=read(),Max=0,Min=n,s1=0,s2=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) Max=max(Max,a[i]);
	for (int i=1;i<=n;i++) Min=min(Min,a[i]);
	if (Max-Min>1) return 0;
	if (Max==Min) return a[1]==n-1||a[1]<=n/2;
	for (int i=1;i<=n;i++) if (a[i]==Min) s1++;
	for (int i=1;i<=n;i++) if (a[i]==Max) s2++;
	return 0<Max-s1&&Max-s1<=s2/2&&(s1+1<=Max||Max<=s1+s2/2);
}

int main()
{
	puts(solve()?"Yes":"No");

	return 0;
}