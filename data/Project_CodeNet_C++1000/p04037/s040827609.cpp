#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[100010];
bool cmp(int a,int b) { return a>b; }
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for (int i=1,x;i<=n;i++) if (a[i+1]<i+1&&a[i]>=i)
	{
		x=0;
		while (a[i+x+1]==i) x++;
		if ((a[i]-i)%2==0&&x%2==0) printf("Second\n"); else printf("First\n");
	}
}