#include<iostream>
#include<algorithm>
#include<vector>
#define LL long long
int N, K;
LL A[100010];
LL sum[32];
LL KS[32];
LL ans;
int main() {
	std::cin >> N >> K;
	int tmp = 0;
	KS[0] = K;
	for (int i = 30; i >= 1; i--) {
		if (K >> i & 1) {
			KS[i] += tmp + (1 << i) - 1;
			tmp += 1 << i;
		}
	}
	for (int i = 0; i < N; i++) {
		LL A, B;
		std::cin >> A >> B;
		for (int i = 0; i <= 30; i++) {
			if ((KS[i] & A) == A) {
				sum[i] += B;
			}
		}
	}
	for (int i = 0; i <= 30; i++) {
		ans = std::max(sum[i], ans);
	}
	std::cout << ans << std::endl;
	return 0;
}