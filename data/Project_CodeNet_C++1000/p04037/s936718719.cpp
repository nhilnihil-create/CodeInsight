//巧妙地转化成矩形后，打表即可发现SG规律 
#include<cstdio>
#include<algorithm>
#define N 100005
using namespace std;
int n,a[N];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	int pos=1,l1=0,l2=0;
	while(pos+1<=a[pos+1])pos++;
	l1=a[pos]-pos;
	for(int i=pos+1;i<=n&&a[i]==pos;i++)l2++;
	if((l1&1)||(l2&1))puts("First");
	else puts("Second");
	return 0;
}