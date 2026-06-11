#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1e3;

int read()
{
	int s=0;
	char c=getchar();
	while (c<'0'||'9'<c) c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return s;
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
void print(int x)
{
	write(x);
	putchar('\n');
}
int n,a[N];
bool check(int m)
{
	pair<int,int>Min(INT_MAX,INT_MAX);
	for (int i=1;i<=2*n-2;i++)
	if ((a[i]>=m)==(a[i+1]>=m))
	Min=min(Min,make_pair(min(abs(n-i),abs(n-i-1)),(int)(a[i]>=m)));
	if (Min.first==INT_MAX) return a[1]>=m;
	return Min.second;
}

int main()
{
	n=read();
	for (int i=1;i<=2*n-1;i++) a[i]=read();
	int l=0,r=2*n-1;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)) l=mid+1;
				   else r=mid-1;
	}
	print(r);

	return 0;
}