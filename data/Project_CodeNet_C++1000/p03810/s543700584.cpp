#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100000
using namespace std;
int n,a[MAXN+5];
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
bool DFS()
{
	int cnt[2]={};
	for(int i=1;i<=n;i++)
		cnt[a[i]%2]++;
	if(cnt[0]%2==1)
		return true;
	if(cnt[1]>=2)
		return false;
	for(int i=1;i<=n;i++)
		if(a[i]%2==1)
		{
			if(a[i]==1)
				return false;
			a[i]--;
		}
	int d=0;
	for(int i=1;i<=n;i++)
		d=gcd(d,a[i]);
	for(int i=1;i<=n;i++)
		a[i]/=d;
	if(DFS()==false)
		return true;
	return false;
}
int main()
{
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(DFS()==true)
		printf("First\n");
	else
		printf("Second\n");
	return 0;
}