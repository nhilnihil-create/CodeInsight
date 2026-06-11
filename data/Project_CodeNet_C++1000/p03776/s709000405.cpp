#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll maxn=1e6;
ll k[maxn];
ll n,ans=0,q[100][100];
int c,d;
int a,b;
ll way;

void yang()
{
	q[0][0]=1;
	q[1][0]=1;
	q[1][1]=1;
	for (int i=2;i<=50;i++)
	{
		q[i][0]=1;
		for(int j=1;j<=i;j++)
			q[i][j]=q[i-1][j]+q[i-1][j-1];
	}
}
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	yang();
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
	}
	sort(k+1,k+n+1,cmp);
if(k[1]==k[a])
{	
	c=a;
	for(int i=a;i<n;i++)
	{
	
		if(k[i]==k[i+1])
		c++;
		else break;
	}
	for(int i=a;i<=min(b,c);i++)
	{
		way+=q[c][i];
	}
}
if(k[1]!=k[a])
{
for(int i=1;i<=n;i++)
{
	if(k[i]==k[a])
	{
		c++;
	}
}
for(int i=1;i<=a;i++)
{
	if(k[i]==k[a])d++;
}
way=q[c][d];
}
	for(int i=1;i<=a;i++)
	{
		ans+=k[i];
	}
	printf("%.6lf\n",(double)ans/a);
	cout<<way;
	return 0;
}