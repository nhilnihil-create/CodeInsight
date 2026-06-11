#include<cstdio>
#include<algorithm>
using namespace std;
long long n, x;
long long func(long long h, long long w) {
	if (h == 0 && w == 0) return 0;
	else if (h == 0) return -w;
	else if (w == 0) return -h;
	if (h > w) return h / w * w * 2 + func(h%w, w);
	else return w / h * h * 2 + func(h, w%h);
}
int main() {
	scanf("%lld%lld", &n, &x);
	long long ans = n;
	printf("%lld", ans+func(n-x, x));
	return 0;
}