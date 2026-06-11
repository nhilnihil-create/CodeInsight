#include <bits/stdc++.h>

int main()
{
	int N;
	scanf("%d", &N);
	std::vector<int64_t> a(3 * N);
	for (auto& e: a) scanf("%lld", &e);
	std::vector<int64_t> former(N + 1), latter(N + 1);
	std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> formerPQ;
	std::priority_queue<int64_t> latterPQ;
	for (int i{}; i < N; i++)
	{
		former.front() += a[i];
		formerPQ.push(a[i]);
	}
	for (int i{}; i < N; i++)
	{
		formerPQ.push(a[N + i]);
		former[i + 1] = former[i] + a[N + i] - formerPQ.top();
		formerPQ.pop();
	}
	for (int i{N - 1}; i >= 0; i--)
	{
		latter.back() += a[2 * N + i];
		latterPQ.push(a[2 * N + i]);
	}
	for (int i{N - 1}; i >= 0; i--)
	{
		latterPQ.push(a[N + i]);
		latter[i] = latter[i + 1] + a[N + i] - latterPQ.top();
		latterPQ.pop();
	}
	int64_t ans{LLONG_MIN};
	for (int i{}; i <= N; i++)
		ans = std::max(ans, former[i] - latter[i]);
	printf("%lld\n", ans);

	return 0;
}