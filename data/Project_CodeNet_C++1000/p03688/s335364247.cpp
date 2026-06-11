#include<iostream>
#include<cstdio> 
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int Min=*min_element(a+1,a+n+1),Max=*max_element(a+1,a+n+1);
	if(Max>=n)
	{
		printf("No");
		return 0;
	}
	if(Max-Min>1)
	{
		printf("No");
		return 0;
	}
	if(Max==Min) 
	{
		if(Min==1||Min+1==n) printf("Yes");
		else if(Min*2>n) printf("No");
		else printf("Yes");
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(a[i]==Min) cnt++;
	n-=cnt;
	Max-=cnt;
	if(Min<cnt) printf("No");
	else if(Max*2>n) printf("No");
	else printf("Yes");
	return 0;
}