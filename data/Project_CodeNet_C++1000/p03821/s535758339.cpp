#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<deque>
#include<map>
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
int main() {
	ll N, M, c = 0, p;
	scanf("%lld", &N);
	vector<ll> A(N), B(N), D(N);
	rep(i, 0, N) {
		scanf("%lld%lld", &A[i], &B[i]);
	}
	for (int i = N - 1; i >= 0; i--) {
		c += (B[i] - A[i] % B[i]) % B[i];
		if (i)A[i - 1] += c;
	}
	printf("%lld\n", c);
	return 0;
}