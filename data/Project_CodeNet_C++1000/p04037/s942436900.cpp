#include<cstdio>
#include<algorithm>
using std::sort;
inline bool cmp(int a,int b)
{
	return a>b;
}
int n,a[100007],x,y;
int main()
{
	scanf(" %d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf(" %d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(x=1;a[x+1]>x;++x);
	for(y=x;a[y]>=x;++y);--y;
	printf("%s\n",(((a[x]-x)&1)|((y-x)&1))?"First":"Second");
	return 0;
}