#include <iostream>
using namespace std;
int n,a,b,arr[100005];
bool check(int mid)
{
	long long add=0;
	for (int i=0;i<n;i++)
	{
		if (arr[i]>1LL*mid*b)
		add+=(arr[i]-mid*b+a-b-1)/(a-b);
	}
	return (add<=mid);
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	int st=0,en=1e9;
	while (st!=en)
	{
		int mid=(st+en)/2;
		if (check(mid))
		en=mid;
		else
		st=mid+1;
	}
	printf("%d",st);
}