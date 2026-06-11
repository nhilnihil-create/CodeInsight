#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005];
int main()
{
	scanf("%d",&n);
	n*=2;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=2*n;i+=2)
		ans+=min(a[i],a[i+1]);
	printf("%d",ans);
	return 0;
}