#include <cstdio>
#include <vector>

typedef long long LL;

std::vector<int> Solve(LL N) {
	if (N == 1) return std::vector<int>();
	if (N & 1) {
		auto v = Solve(N - 1);
		v.insert(v.begin(), (int)v.size() + 1);
		return v;
	}
	auto v = Solve(N / 2);
	v.push_back((int)v.size() + 1);
	return v;
}

int main() {
	LL N;
	scanf("%lld", &N);
	auto Ans = Solve(N + 1);
	printf("%d\n", 2 * (int)Ans.size());
	for (int x : Ans) printf("%d ", x);
	for (int i = 1; i <= (int)Ans.size(); ++i) printf("%d ", i);
	puts("");
	return 0;
}