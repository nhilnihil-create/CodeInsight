#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long  a[3];
	for(int i = 0; i <= 2; i++)
		cin >> a[i];
	sort(a, a+3);
	if(a[2] % 2 == 0 || a[0] %2 ==0 || a[1] %2 == 0)
		printf("0");
	else{
		long long ans = a[0] * a[1];
		printf("%lld", ans);
	}
	
	return 0;
} 