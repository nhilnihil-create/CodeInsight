#include <iostream>
#include <stdio.h> 
#include <algorithm>
using namespace std;

long long int a[3];

int main()
{
	int max1 = 0, sum = 0, result = 0;
	for(int i=0;i<3;i++)
	{
		scanf("%lld", &a[i]);
		if(a[i]%2==0)
		{
			printf("0\n");
			return 0;
		}		
	}	
	sort(a, a+3);
	long long int ans = a[0]*a[1];
    printf("%lld\n", ans);
	return 0;
}
