#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100010
int a[MAXN],n,f;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		if(i+1>a[i+1])
		{
			if((a[i]-i)%2) f=1;
			bool c=0;
			for(int j=i+1;a[j]==i&&!f;j++)
				c^=1;
			if(c==1) f=1;
			break;
		}
	if(f) printf("First\n");
	else printf("Second\n");
}