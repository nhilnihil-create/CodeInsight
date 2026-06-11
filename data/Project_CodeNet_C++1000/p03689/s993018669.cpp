#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=505;
const int d=4000;

int n,m,x,y,a[N][N];

int main()
{
	scanf("%d%d%d%d",&n,&m,&x,&y);
	if (n%x==0&&m%y==0) {puts("No");return 0;}
	puts("Yes");
	for (int i=x;i<=n;i+=x)
		for (int j=y;j<=m;j+=y)
			a[i][j]=-x*y*d+d-1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) printf("%d ",!a[i][j]?d:a[i][j]);
		puts("");
	}
	return 0;
}