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

int main()
{
	int32_t N;
	scanf("%d", &N);

	int32_t cnt[100001];
	memset(cnt, 0, sizeof(cnt));
	for (int32_t i = 0; i < N; i++) {
		int32_t A;
		scanf("%d", &A);
		cnt[A]++;
	}

	vector<int32_t> B;
	for (int32_t i = 0; i < 100001; i++) {
		if (cnt[i] < 1)
			continue;
		B.push_back(cnt[i] % 2 == 0 ? 2 : 1);
	}

	int32_t left = 0, right = (int32_t)(B.size() - 1);
	while (left < right) {
		if (B[left] == 1 && B[right] == 1) {
			left++;
			right--;
		} else if (B[left] == 1 && B[right] == 2) {
			left++;
		} else if (B[left] == 2 && B[right] == 1) {
			right--;
		} else if (B[left] == 2 && B[right] == 2) {
			B[left] = 1;
			B[right] = 1;
			left++;
			right--;
		}
	}
	int32_t res = B.size();
	for (size_t i = 0; i < B.size(); i++)
		if (B[i] == 2)
			res--;

	printf("%d\n", res);

	return 0;
}