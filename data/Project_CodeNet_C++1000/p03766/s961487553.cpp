#include <cstdio>
typedef long long ll;

const int N = 1001000, p = 1e9+7;
inline int qm(const int x) {return x < p ? x : x - p;}
int n, a, b, c, d;

int main() {
	scanf("%d",&n);
	if(n == 1) return puts("1"), 0;
	if(n == 2) return puts("4"), 0;
	c = n, b = (ll)n * n%p;
	int sm = 0;
	for(int i=n-2;i;--i) {
		sm = qm(sm + d);
		a = (sm + b + (ll)(n-1)*(n-1) + i+1)%p;
		d = c, c = b, b = a;
	}
	printf("%d\n", b);
	return 0;
}