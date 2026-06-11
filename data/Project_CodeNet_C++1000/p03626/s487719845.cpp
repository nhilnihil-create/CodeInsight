#include <cstdio>
#define MANX 60
#define ll long long
#define mod 1000000007
#define MAXN 60
char a[MAXN], b[MAXN];
int main() {
	int n, i = 1;
	ll ans = 1;
	bool flag; 
	scanf("%d", &n); 
	scanf("%s\n%s", a+1, b+1);
	if(n == 1) {
		printf("3\n");
		return 0;
	}	
	if(a[1] == a[2]) {
		flag = 1;
		i += 2;
		ans = 6;
	}
	else
	{
		flag = 0;
		i ++;
		ans = 3;
	}
	while(i <= n) {
		if(a[i] == b[i]) {
			if(flag == 1) {
				ans *= 1;
			} 
			else {
				ans = (ans*2) % mod;
			} 
			flag = 0; 
			i ++;
		}else { 
			if(flag == 1) {
				ans = (ans*3) % mod; 
			}else {
				ans = (ans*2) % mod;
			}
			flag = 1;
			i += 2;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
