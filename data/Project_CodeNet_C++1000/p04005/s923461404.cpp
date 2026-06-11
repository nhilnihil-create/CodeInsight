#include <stdio.h>
#include<algorithm>

using namespace std;

int main(){
	long long  a[3],b=0;
	scanf("%lld %lld %lld",&a[0],&a[1],&a[2]);
	sort(a,a+3);
	b=(a[2]%2)*(a[1]*a[0]);
	printf("%lld",b);
	return 0;
}