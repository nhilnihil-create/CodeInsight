#include <iostream>
using namespace std;
int arr[7];
long long f(int x)
{
	if (x<0)
	return -1e9;
	return x-x%2;
}
int main()
{
	for (int i=0;i<7;i++)
	scanf("%d",&arr[i]);
	printf("%lld",arr[1]+max(f(arr[0])+f(arr[3])+f(arr[4]),f(arr[0]-1)+f(arr[3]-1)+f(arr[4]-1)+3));
}