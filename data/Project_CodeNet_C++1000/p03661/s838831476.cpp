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
const int MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int N, M, K, Q;
ll psum[MAX];

int main()
{
	int i, j, k;
	scanf("%d", &N);
	ll x;
	for (i = 1; i <= N; ++i) {
		scanf("%lld", &x);
		psum[i] = psum[i - 1] + x;
	}
	ll mini = LINF;
	for (i = 1; i < N; ++i) {
		mini = min(mini, abs(psum[i] - (psum[N] - psum[i])));
	}
	printf("%lld", mini);
}
