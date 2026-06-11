#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
const int mod = 1e9+7;

int h,w,a,b;
long long ret;
int fac[maxn];

void exgcd(int a, int b, int &g, int &x, int &y) {
	if (b == 0) g = a, x = 1, y = 0;
	else exgcd(b,a%b,g,y,x), y -= a/b*x;
}

int inv(int a) {
	int g,x,y;
	exgcd(a, mod, g, x, y);
	return (x+mod) % mod;
}

int C(int n,int m) {
	return (long long)fac[n] * inv(fac[m]) % mod * inv(fac[n-m]) % mod;
}

int f(int n, int m) {
	return C(n+m-2, n-1);
}

int main() {
	fac[0] = 1;
	for (int i = 1; i <= maxn; i++) fac[i] = (long long)fac[i-1]*i%mod;
	scanf("%d%d%d%d",&h,&w,&a,&b);
	for (int i = 1; i <= h-a; i++) {
		ret = (ret + (long long)f(i,b) * f(h-i+1,w-b))%mod;
	}
	printf("%d\n",ret);
	return 0;
}