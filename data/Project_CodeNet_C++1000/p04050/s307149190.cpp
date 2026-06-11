#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100010
int a[MAXN],b[MAXN];
int main()
{
	int n,m,cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]%2) cnt++;
	}
	if(cnt>2)
	{
		printf("Impossible\n");
		return 0;
	}
	bool f=1;
	for(int i=0;i<m;i++)
		if(a[i]%2)
		{
			if(f) swap(a[i],a[0]),f=0;
			else swap(a[i],a[m-1]);
		}
	if(m==1)
	{
		if(a[0]==1) printf("1\n1\n1\n");
		else printf("%d\n2\n%d 1\n",a[0],a[0]-1);
		return 0;
	}
	b[0]=a[0]+1;
	for(int i=1;i<m-1;i++)
		b[i]=a[i];
	f=1;
	for(int i=0;i<m;i++)
	{
		if(f) printf("%d",a[i]),f=0;
		else printf(" %d",a[i]);
	}
	if(a[m-1]==1) m--;
	else b[m-1]=a[m-1]-1;
	printf("\n%d\n%d",m,b[0]);
	for(int i=1;i<m;i++)
		printf(" %d",b[i]);
	printf("\n");
}