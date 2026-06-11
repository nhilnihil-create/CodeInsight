#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
int a[100010];
int main()
{
#ifdef DEBUG
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	int n;
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	int ans;
	a[0]=a[1];
	for(i=0;i<=n;i++)
		if(a[i+1]<=i)
		{
			ans=(a[i]-i)&1;
			int j=i+1;
			while(j<=n&&a[j]==i)
				j++;
			if((j-i+1)&1)
				ans=1;
			break;
		}
	if(ans)
		printf("First\n");
	else
		printf("Second\n");
	return 0;
}