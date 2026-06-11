#include <cstdio>
#include <algorithm>
using namespace std;

int a[100005] = {0};
int main()
{	
	int n,max,r,t;
	
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&t);
		a[t]++;
		a[t + 1]++;
		a[t + 2]++;		
	}
	r = *max_element(a,a+100005);
	printf("%d\n",r);
	
	return 0;
}