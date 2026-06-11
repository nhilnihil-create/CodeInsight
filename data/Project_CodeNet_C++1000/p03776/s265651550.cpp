//组合数=杨辉三角 
#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=55;
int n,a,b;
ll v[N],c[N][N];
bool cmp(ll x,ll y)
{
	return x>y;
}

void pre()//杨辉三角求组合数 Cn^m=n!/(m!(n-m)!) =杨辉三角第n-1层第m-1个数 即从n中取m个的方案数 Cn^0+Cn^1+.....+Cn^n=2^n<2^64 50!>ll
{

	for(int i=0;i<=50;i++)
	{
		c[i][0]=1;c[i][i]=1;
	}
	for(int i=1;i<=50;i++)
	{
		for(int j=1;j<i;j++)
		{
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
}

int main()
{
	double ave=0;
	ll m=0,sum=0;
	scanf("%d%d%d",&n,&a,&b);
	
	pre();
	
/*	for(int i=0;i<=50;i++)
	{
		for(int j=0;j<=i;j++)
		{
			printf("%lld ",c[i][j]);
		}
		printf("\n");
	}
*/	
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&v[i]);
	}
	
	sort(v+1,v+1+n,cmp);
	for(int i=1;i<=a;i++)
	{
		sum+=v[i];
	}
	ave=(double)sum/a;

	int num1=0,num2=0;
	for(int i=1;i<=n;i++)
	{
		if(v[i]==v[a])
		{
			num1++;
			if(i>=a)
			{
				num2++;
			}
		}
	}
	if(v[1]==v[a])
	{
		for(int i=a;i<=min(num1,b);i++)
		{
			m+=c[num1][i];
		}
	}
	else
	{
		num2--;
		m=c[num1][num2];//cout<<num1<<" "<<num2<<" "<<endl;
	}
	printf("%lf\n%lld",ave,m);
	return 0;

}
/*
8 2 5
1 1 2 2 3 3 3 3

11
*/