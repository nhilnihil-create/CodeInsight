#include<bits/stdc++.h>
using namespace std;

int num[510][510];
int n,m,A,B;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(int x)
{
	static char s[233];
	if (x<0) putchar('-'),x=-x;
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

int main()
{
	n=rd();m=rd();A=rd();B=rd();
	if (n%A==0&&m%B==0) { puts("No");return 0; }
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (i%A==0&&j%B==0) num[i][j]=-2000*(A*B-1)-1;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (!num[i][j]) num[i][j]=2000;
	puts("Yes");
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) print(num[i][j]);
		putchar('\n');
	}
	return 0;
}