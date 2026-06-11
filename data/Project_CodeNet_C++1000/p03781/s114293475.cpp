#include<bits/stdc++.h>

using namespace std;


int main() 
{
	long long  n;
	scanf("%lld",&n);
	long long ans = 0;
	long long i = 0;
	for(i = 1; ans + i < n; i++)
	{
//		printf("%d\n",ans);
		ans += i;
	}
	printf("%lld\n",i);
	return 0;
}
