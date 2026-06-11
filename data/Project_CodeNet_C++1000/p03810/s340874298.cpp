#include<cstdio> 
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
using namespace std;
#define fo(i,j,k) for(i=j;i<=k;i++)
#define fd(i,j,k) for(i=j;i>=k;i--)
#define cmax(a,b) (a=(a>b)?a:b)
#define cmin(a,b) (a=(a<b)?a:b)
typedef long long ll;
const int N=1e6+5,M=2e6+5,mo=1e9+7;
int a[N],d,x,i,n,pp;
int gcd(int a,int b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
int dfs()
{
	x=0;
	pp=0;
	fo(i,1,n) if (a[i]%2==0) x++;
	else 
	{
		if (a[i]==1) pp=1;
		a[i]--;
	}
	if (x%2) return 0;
	if (x==n-1&&!pp)
	{
		d=a[1];
		fo(i,2,n) d=gcd(d,a[i]);
		fo(i,1,n) a[i]/=d;
		return dfs()^1;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	fo(i,1,n) 
		scanf("%d",a+i);
	if (dfs()==0) printf("First");else
	printf("Second");
}