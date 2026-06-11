#include <bits/stdc++.h>
using namespace std;

int n,m,d,a[1010][1010],c[4];
char ch[]="RYGB";

void work()
{
	scanf("%d %d %d",&n,&m,&d);
	if (d&1)
		{
			for (int i=1; i<=n; i++,puts(""))
				for (int j=1; j<=m; j++)
					a[i][j]=(i+j)&1,putchar((i+j)&1?'Y':'R');
			return;
		}
	int x,y;
	for (int i=1; i<=n; i+=d)
		for (int j=1; j<=m; j+=d)
			{
				x=(i/d+j/d)&1,y=2+x;
				for (int k=0,p=0,q=d; p<q; k++,p++,q--)
					for (int l=p; l<q; l++)
						a[i+k][j+l]=x;
				for (int k=d-1,p=1,q=d-1; p<q; k--,p++,q--)
					for (int l=p; l<q; l++)
						a[i+k][j+l]=x^1;
				for (int k=0,p=1,q=d; p<q; k++,p++,q--)
					for (int l=p; l<q; l++)
						a[i+l][j+k]=y,a[i+l][j+d-k-1]=y^1;
			}
	for (int i=1; i<=n; i++,puts(""))
		for (int j=1; j<=m; j++)
			putchar(ch[a[i][j]]);
}

int main()
{
	work();
	return 0;
}
