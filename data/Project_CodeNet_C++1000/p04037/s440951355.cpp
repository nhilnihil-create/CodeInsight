#include<algorithm>
#include<cstdio>
using namespace std;
int n,p,t,a[100005];
bool bz;
bool cmp(int a,int b){return a>b;}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for (;a[p+1]>=p+1;p++);
	for (;a[p+t]>=p;t++); 
	if ((a[p]-p+1)&1 && t&1) bz=1;
	printf(bz?"Second":"First");
	return 0;
}
