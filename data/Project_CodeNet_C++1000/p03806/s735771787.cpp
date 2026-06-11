#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

#include <inttypes.h>
using namespace std;

static int32_t N, Ma, Mb;
static int32_t a[40], b[40], c[40];
static int32_t memo[41][401][401];

static int32_t dfs(int32_t _index, int32_t sum_a, int32_t sum_b)
{
	if (memo[_index][sum_a][sum_b] > -1)
		return memo[_index][sum_a][sum_b];

	int32_t res = dfs(_index + 1, sum_a + a[_index], sum_b + b[_index]) + c[_index];
	res = min(res, dfs(_index + 1, sum_a, sum_b));
	memo[_index][sum_a][sum_b] = res;
	return res;
}

int main()
{
	scanf("%d%d%d", &N, &Ma, &Mb);
	int32_t max_cost = 0;
	for (int32_t i = 0; i < N; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		max_cost += c[i];
	}

	for (int32_t _index = 0; _index <= N; _index++)
		for (int32_t sum_a = 0; sum_a < 401; sum_a++)
			fill(memo[_index][sum_a], memo[_index][sum_a] + 401, -1);

	for (int32_t sum_a = 0; sum_a < 401; sum_a++) {
		for (int32_t sum_b = 0; sum_b < 401; sum_b++) {
			memo[N][sum_a][sum_b] =
				(sum_a > 0 && sum_b > 0 && sum_a * Mb == sum_b * Ma) ? 0 : numeric_limits<int32_t>::max() / 2;
		}
	}

	int32_t res = dfs(0, 0, 0);
	printf("%d\n", res > max_cost ? -1 : res);

	return 0;
}