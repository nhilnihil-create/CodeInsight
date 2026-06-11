#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	long long int n,x,i;
	scanf("%lld %lld",&n,&x);
	long long int a = n, b = n-x;
	if(a<b)swap(a,b); 
	while (b!=0)
	{
		long long int x=a; 
		a=b;
		b=x%b;
		if(a<b)swap(a,b);
	}
	printf("%lld",3*(n-a));
}