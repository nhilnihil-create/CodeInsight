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
int N, K, Q;
ll M;
ll A[MAX], pdiff[2*MAX], ch[2*MAX];

int main()
{
	int i, j, k;
	scanf("%d%lld", &N, &M);
	for (i = 1; i <= N; ++i) {
		scanf("%lld", &A[i]);
	}
	ll tot = 0;
	for (i = 2; i <= N; ++i) {
		ll l = A[i - 1];
		ll r = A[i];
		if (l > r) r += M;
		tot += r - l;
		pdiff[l + 1]++;
		pdiff[r + 1]--;
		ch[r + 1] -= r - l;
	}
	
	for (i = 1; i <= 2 * M; ++i) {
		pdiff[i] += pdiff[i - 1];
		ch[i] += ch[i - 1] + pdiff[i];
	}
	ll mini = tot;
	for (i = 1; i <= M; ++i) mini = min(mini, tot - ch[i] - ch[i + M] + pdiff[i] + pdiff[i + M]);
	printf("%lld", mini);
}