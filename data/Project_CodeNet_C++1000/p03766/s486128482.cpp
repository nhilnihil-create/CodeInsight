#include <stdio.h>
#include <set>
#include <bitset>
#include <string.h>
#include <algorithm>
#include <queue>
#include <cctype>
using namespace std;
#define rep(i, a, b) for(register LL i = (a), i##_end_ = (b); i <= i##_end_ ; ++i)
#define drep(i, a, b) for(register LL i = (a), i##_end_ = (b); i >= i##_end_ ; --i)
typedef long long LL;
#define inf (0x3f3f3f3f)
LL read() {
	LL x = 0, flag = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') flag = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = (x << 3) + (x << 1) + (ch - 0x30);
		ch = getchar();
	}
	return flag * x;
}

const LL Maxn = (int)(1e7), Mod = (int)(1e9 + 7); 
LL n, f[Maxn], prefix[Maxn];
LL sum;
int main() {
	n = read();
	f[1] = n; f[2] = n * n % Mod;
	rep(i, 3, n) {
		f[i] = (f[i - 1] + sum) % Mod + (n - 1) * (n - 1) % Mod;
		f[i] = (f[i] + n - i + 2) % Mod;
		sum += f[i - 2];
	}
	printf("%lld\n", f[n]);
	return 0;
}