#pragma GCC optimize (2)
#include<bits/stdc++.h>
using namespace std;
const int N=100000+5;
int a[N];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}

int main()
{
	int n=read();
	for (int i=1; i<=n; i++) a[i]=read();
	sort(a+1, a+n+1, greater<int>());
	for (int i=1; i<=n; i++) if (i+1>a[i+1])
	{
		int ans=0;
		for (int j=i+1; a[j]==i; j++) ans^=1;
		ans|=((a[i]-i)&1);
		if (ans) puts("First"); else puts("Second");
		return 0;
	}
	return 0;
}
