#include <bits/stdc++.h>
using namespace std;

int n,a[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		if(i+1>a[i+1])
		{
			int ji=i+1,pd=0;
			while(a[ji]==i)
			{
				pd^=1;
				++ji; 
			} 
			if(pd||(a[i]-i)%2==1)
			printf("First\n");
			else
			printf("Second\n");
			break;
		}
	}
	return 0;
}