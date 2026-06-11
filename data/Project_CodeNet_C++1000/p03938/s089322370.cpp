#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e4 + 5;

int A[N], B[N], P[N], n;

main() {
	cin >> n;
	for(int i = 1; i <= n; ++ i) scanf("%lld", &P[i]);
	for(int i = 1; i <= n; ++ i) A[i] = B[n - i + 1] = N * i;
	for(int i = 1; i <= n; ++ i) 
	A[P[i]] += i;
	for(int i = 1; i <= n; ++ i) printf("%lld ", A[i]);
	puts("");
	for(int i = 1; i <= n; ++ i) printf("%lld ", B[i]);
	puts("");
}