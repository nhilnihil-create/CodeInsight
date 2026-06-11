#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <cmath>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define PI 3.14159265
using namespace std;
const int MAX = 1e5 + 10;
const ll MOD = 1e9 + 7;
int N, M, Q;
ll K;
ll A[60];

int main()
{
	int j, k;
	scanf("%lld", &K);
	ll limit = 1e16 + 1000;
	ll least, n;
	if (K > 50) {
		n = 50;
		least = K / n;
		for (int i = 1; i <= n; ++i) A[i] = least + n - i;
		for (int i = 1; i <= K % n; ++i) A[i]++;
		printf("50\n");
		for (int i = 1; i <= n; ++i) printf("%lld ", A[i]);
		return 0;
	}
	else if (K == 1) {
		printf("2\n2 0");
		return 0;
	}
	vector<ll> divs;
	for (ll num = 2; num <= 50; ++num) {
		if (K%num == 0) divs.push_back(num);
	}
	for (int i = divs.size()-1; i >= 0; --i) {
		n = divs[i];
		least = K / n;
		if (least + n - 1LL > limit) continue;
		break;
	}
	printf("%lld\n", n);
	for (ll i = 0; i < n; ++i) {
		printf("%lld ", least + n - 1 - i);
	}

}
