#include<stdio.h>
#include<stdlib.h>
 
 
int main()
{ 
	long long int n;
	scanf("%lld",&n);	
	long long int *a = NULL;
	a = (long long int *)malloc(sizeof(long long int)*n);
	long long int *b = NULL;
	b = (long long int *)malloc(sizeof(long long int)*n);
	

	long long int sum = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		sum += a[i];
	 }
	long long int t = 0,m;
		 
	for (int i = 0; i<n;i++)
	{
		t += a[i];
		if (sum - 2 * t >= 0) 
			b[i] = sum - 2 * t;
		else b[i]=2*t-sum;
	}
	m = b[0];
	for (int i = 0; i < n-1; i++)
		if (b[i] < m)
			m = b[i];
 
	
	printf("%lld\n", m);
	free(a);
	free(b);
	return 0;
}