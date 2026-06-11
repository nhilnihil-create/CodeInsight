#include <iostream>
using namespace std;
int arr[100005];
int main()
{
	int n;
	scanf("%d",&n);
	long long sum=0,cnt=0;
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]),sum+=arr[i];
	long long tmp=1LL*n*(n+1)/2;
	if (sum%tmp)
	{
		printf("NO");
		return 0;
	}
	sum/=tmp;
	for (int i=0;i<n;i++)
	{
		long long cur=arr[i]-(arr[(i+1)%n]-sum);
		if (cur<0 || cur%n)
		{
			printf("NO");
			return 0;
		}
		cnt+=cur/n;
	}
	printf((cnt==sum)? "YES":"NO");
}