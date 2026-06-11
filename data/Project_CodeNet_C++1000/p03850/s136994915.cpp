#include <iostream>
#include <algorithm>

using ui = uint64_t;
using li = int64_t;

li num[100100];
char op[100100];

const li INF = li(100100) * 1000000000;
li dp[100100];
//op[i]==-
li func(int i)
{
	//i以降（i含む)で最大
	if (op[i + 1] == '-') { return dp[i]  = -(num[i] - num[i + 1]) + num[i + 1]; }
	if (dp[i] != INF) { return dp[i]; }
	return dp[i] = -(num[i] - num[i+1])
		+ std::max(
			-(num[i + 1] - num[i + 2]) + num[i + 2],
			+(num[i + 1] - num[i + 2]) + func(i + 2)
		);
}

int main()
{
	for (auto& i : dp) {
		i = INF;
	}
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);
	int N;
	std::cin >> N;
	std::cin >> num[0];
	int temp_n = 1;
	bool is_mode_add = true;
	for (int i = 1; i < N; ++i) {
		std::cin >> op[temp_n];
		std::cin >> num[temp_n];
		bool next_mode = (op[temp_n] == '+');
		if (is_mode_add && next_mode) {
			num[temp_n - 1] += num[temp_n];
		}
		else {
			is_mode_add = next_mode;
			++temp_n;
		}
	}
	//番兵
	op[temp_n] = op[temp_n + 1] = '-';
	num[temp_n] = num[temp_n + 1] = 0;
	//numを累積和に
	for (int i = temp_n - 1; i >= 0; --i) {
		num[i] += num[i + 1];
	}

	li res = (num[0] - num[0 + 1]);
	if (temp_n > 1) {

		res += func(1);
	}
	std::cout << res << std::endl;
}
