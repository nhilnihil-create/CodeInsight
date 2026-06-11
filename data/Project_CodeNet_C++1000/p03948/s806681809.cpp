#include <iostream>
using namespace std;
int main()
{
	int n,t,mn=(1<<30),mx=0,cnt=0;
	scanf("%d%d",&n,&t);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		mn=min(mn,a);
		if (a-mn>mx)
		{
			mx=a-mn;
			cnt=0;
		}
		if (a-mn==mx)
		cnt++;
	}
	printf("%d",cnt);
}