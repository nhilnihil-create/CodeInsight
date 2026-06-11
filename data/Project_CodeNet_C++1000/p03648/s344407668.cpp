#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long w[51];
int main() {
	int i;
	long long n;
	scanf("%lld", &n);
	if (n <= 50) {
		printf("%d\n", 50);
		for (i = 1; i <= 50; i++) {
			if (i <= n)printf("%d ", 50);
			else printf("%d ", 0);
		}
		printf("\n");
		return 0;
	}
	for (i = 1; i <= 50; i++)w[i] = 50-i+(n/50);
	for (i = 1; i <= (n % 50); i++)w[i]++;
	printf("%d\n", 50);
	for (i = 1; i <= 50; i++)printf("%lld ", w[i]);
}