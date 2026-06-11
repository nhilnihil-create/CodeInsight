#include <iostream>
using namespace std;
int main()
{
	long long k;
	scanf("%lld",&k);
	printf("50\n");
	for (int i=0;i<50;i++)
	printf("%lld ",i+k/50+(i>=50-k%50));
}