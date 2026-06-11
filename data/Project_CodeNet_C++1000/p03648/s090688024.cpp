#include <bits/stdc++.h>

using namespace std;

const int n = 50;

long long k, q, a[55];

int main(){
//	freopen("input.inp", "r", stdin);
	scanf("%lld",&k);
	for(int i = 1; i <= n; ++i) a[i] = n - 1 + k / n;
	q = k % n;
	for(int i = 1; i <= q; ++i) a[i] += n - q;
	for(int i = q + 1; i <= n; ++i) a[i] -= q;
	printf("%d\n", n);
	for(int i = 1; i <= n; ++i) printf("%lld ", a[i]);
	return 0; 
}