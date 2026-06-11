#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005];
bool cmp(const int x,const int y)
{
	return x>y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	int id=0;
	for(int i=1;i<=n;i++)
		if(a[i]>=i) id=i;
	if(id==n||a[id]>a[id+1])
	{
		int nw=id+1;
		while(nw<n&&a[nw+1]==a[id+1]) nw++;
		if((a[id]-id)%2==1||(a[id+1]==id&&(nw-(id+1))%2==0)) printf("First\n");
		else printf("Second\n");
		return 0;
	}
	int nw=id;
	while(nw<n&&a[nw+1]==a[id]) nw++;
	if((nw-id)%2) printf("First\n");
	else printf("Second\n");
	return 0;
} 