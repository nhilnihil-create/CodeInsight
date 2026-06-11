#include <bits/stdc++.h>

using ll = long long;
constexpr ll inf = static_cast<ll>(1e17);
constexpr ll mod = static_cast<ll>(1e9 + 7);

int n, k;
ll a[100005];
ll sum[100005], plusSum[100005];
int main()
{
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		sum[i + 1] = sum[i] + a[i];
		plusSum[i + 1] = plusSum[i] + std::max(0LL, a[i]);
	}

	ll ans = -inf;
	for (int i = 0, end = n - k + 1; i < end; ++i) {
		auto a1 = plusSum[i] + sum[i + k] - sum[i] + plusSum[n] - plusSum[i + k];
		auto a2 = plusSum[n] - plusSum[i + k] + plusSum[i];
		ans = std::max({ ans,a1,a2 });
	}

	std::cout << ans << std::endl;
	return 0;
}
