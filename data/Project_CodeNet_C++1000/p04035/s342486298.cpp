#include<bits/stdc++.h>
using namespace std;
int a[200000];
int main()
{
	int n,l;
	cin>>n>>l;

	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int f = 0,ind;
	for (int i = 0; i < n-1; ++i)
	{
		if(a[i]+a[i+1] >=l)
		{
			f = 1;
			ind = i+1;
			break;
		}
	}
	if(f==0)
	{
		printf("Impossible\n");
	}
	else
	{
		printf("Possible\n");
		for (int i = 1; i <= n-1; ++i)
		{
			if(i==ind)
				break;
			printf("%d\n",i );
		}
		for (int i = n-1; i >= ind; i--)
		{
			printf("%d\n",i );
		}
	}

	
	return 0;
}