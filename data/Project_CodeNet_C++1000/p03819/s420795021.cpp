#include <bits/stdc++.h>
using namespace std;

const int N=300010;
int n,m,i,ql,qr,ans[N];

int read()
{
	int d=0; char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) d=(d<<3)+(d<<1)+ch-48,ch=getchar();
	return d;
}

int main()
{
	m=read(); n=read();
	while (m--)
	{
		ql=read()-1; qr=read();
		for (i=1;i<=ql;)
		{
			int d=qr/i,j=qr/d,k=ql/d;
			ans[max(k+1,i)]++; ans[j+1]--;
			i=j+1;
		}
		ans[i]++; ans[qr+1]--;
	}
	for (int i=1;i<=n;i++)
	{
		ans[i]+=ans[i-1];
		printf("%d\n",ans[i]);
	}
	return 0;
}