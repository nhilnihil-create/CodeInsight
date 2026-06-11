/*		  m 
组合数：Cn 	 （从n个中取m个） 
	
*/ 
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a,b;
long long c[55][55],ans2,v[55],sum;
double ans1;

bool cmp(long long  x,long long  y)
{
	return x>y;
}

void pre()
{
	for(int i=0;i<=n;i++)
	{
		c[i][0]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
} 

int main()
{
	int num=0,num1=0,tot=0;

	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&v[i]);
	}
	pre();	
	sort(v+1,v+n+1,cmp);
	for(int i=1;i<=a;i++)
	{
		sum+=v[i];
		if(v[i]==v[a])
		{
			num1++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==v[a])
		{
			num++;
		}
		if(v[i]==v[1])
		{
			tot++;
		}
	}	
	
	if(v[a]==v[1])
	{
		for(int i=a;i<=min(b,tot);i++)
		{

			ans2+=c[tot][i];
		}
	}
	else 
	{
	
		ans2=c[num][num-num1];	
	}
	ans1=(double)sum/a;
	printf("%.6lf\n%lld",ans1,ans2);
	return 0;
}