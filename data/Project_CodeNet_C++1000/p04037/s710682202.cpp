#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define inf 20021225
#define ll long long
#define mxn 100010
using namespace std;

int n,a[mxn];
bool cmp(int x,int y)
{
	return x>y;
}
void work(int id)
{
	int i,qaq=0;
	for(i=id+1;a[i]==id&&i<n;i++)	qaq^=1;
	if((a[id]-id)%2==1||qaq)	printf("First\n");
	else	printf("Second\n");
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]),a[i]--;
	sort(a,a+n,cmp); int i;
	for(i=0;i<n;i++)
		if(a[i+1]<i+1)
		{
			work(i);break;
		}
	return 0;
}