#include <stdio.h>

int main() 
{
	long long n, x, c, t, y;
	
	scanf("%lld%lld", &n, &x);
	c = n, t = n - x;
	while(1){
		c += 2 * (t / x) * x;
		y = x, x = t % x;
		if(!x){
			c -= y;
			break;
		} 
		t = y;
	}
	printf("%lld\n", c);
			
	return 0;
}