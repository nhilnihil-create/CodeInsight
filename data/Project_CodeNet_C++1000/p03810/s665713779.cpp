#include<cstdio>
using namespace std;
const int N=1e5+10;
int n,a[N];
int gcd(int x,int y)
{
	if (!y) return x;
	return gcd(y,x%y);
}
int dg()
{
	int cnt1=0,cnt2=0,p=0;
	for (int i=1;i<=n;i++) 
	{
		if (a[i]&1) cnt1++;else cnt2++;
		if (a[i]==1) p=1;
	}	
	if (cnt2&1) return 1;
	if (cnt1>1||p) return 0;
	int g;
	for (int i=1;i<=n;i++) if (a[i]&1) 
	{
		g=i;
		break;
	} 
	if (a[g]==1) return 0;
	a[g]--;
	int num=a[1];
	for (int i=2;i<=n;i++) num=gcd(num,a[i]);
	for (int i=1;i<=n;i++) a[i]=a[i]/num;
	return 1-dg();
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (dg()) puts("First"); else puts("Second");
}
 