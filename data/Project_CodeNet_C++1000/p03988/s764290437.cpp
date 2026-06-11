#pragma GCC optimize (2)
#include<bits/stdc++.h>
using namespace std;
int a[105], b[105];

inline int read()
{
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}

void check(bool flag)
	{if (!flag) {puts("Impossible"); exit(0);}}

int main()
{
    int n=read();
    for (int i=1; i<=n; i++) 
		a[i]=read(), check(a[i]<=n), b[a[i]]++;
    sort(a+1, a+n+1); int d=a[n];
    if (d&1)
    {
    	int m=(d>>1)+1;
		check(a[1]==m); check(b[m]==2);
		for (int i=m+1; i<=d; i++) check(b[i]>=2);
		puts("Possible");
	}
	else
	{
		int m=d>>1;
		check(a[1]==m); check(b[m]==1);
		for (int i=m+1; i<=d; i++) check(b[i]>=2);
		puts("Possible");
	}
	return 0;
}
