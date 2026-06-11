#include <bits/stdc++.h>

typedef long long ll;

ll n, x;
ll GetAns(ll a, ll b) {
	if(a < b) std::swap(a, b);
	return a % b ? GetAns(b, a % b) + 2 * (a / b) * b : 2 * (a / b) * b - b;
}

int main() {
	scanf("%lld%lld", &n, &x);
	printf("%lld", GetAns(x, n - x) + n);
	return 0;
}