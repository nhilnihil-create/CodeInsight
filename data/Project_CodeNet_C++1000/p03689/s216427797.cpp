#include<cstdio>
#include<cstdlib>
#include<cstring>
#define llong long long
#define ldouble long double
#define uint unsigned int
#define ullong unsigned long long
#define udouble unsigned double
#define uldouble unsigned long double
#define modinc(x) {if(x>=P) x-=P;}
#define pii pair<int,int>
#define piii pair<pair<int,int>,int>
#define piiii pair<pair<int,int>,pair<int,int> >
#define pli pair<llong,int>
#define pll pair<llong,llong>
#define Memset(a,x) {memset(a,x,sizeof(a));}
using namespace std;

const int N = 500;
int a[N+2][N+2];
int n,m,nn,mm;

int main()
{
	scanf("%d%d%d%d",&n,&m,&nn,&mm);
	llong s = 0ll;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(i%nn==0 && j%mm==0)
			{
				a[i][j] = -nn*mm*1000+999;
			}
			else a[i][j] = 1000;
			s += (llong)a[i][j];
		}
	}
	if(s<=0) printf("No");
	else
	{
		puts("Yes");
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				printf("%d ",a[i][j]);
			}
			if(i!=n) puts("");
		}
	}
	return 0;
}