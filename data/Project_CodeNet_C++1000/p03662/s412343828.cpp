#include <bits/stdc++.h>

int n;
std::vector<int> data[100005];
int d1[100005], d2[100005];

void dfs(const int pos, const bool turn) {
	int *d;
	if (turn) {
		if (pos == n - 1)
			return;
		d = d1;
	}
	if (!turn) {
		if (pos == 0)
			return;
		d = d2;
	}

	for (size_t i = 0, end = data[pos].size(); i < end; ++i) {
		auto dp = data[pos][i];
		auto *dd = &d[dp];
		if (dp != 0 && dp != n - 1 && *dd == -1) {
			*dd = d[pos] + 1;
			dfs(dp, turn);
		}
	}
}

int main()
{
	std::cin >> n;
	std::fill(d1, d1 + n, -1);
	std::fill(d2, d2 + n, -1);
	d1[0] = 0;
	d2[n - 1] = 0;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		std::cin >> a >> b;
		--a, --b;
		data[a].emplace_back(b);
		data[b].emplace_back(a);
	}

	dfs(0, true);
	dfs(n - 1, false);

	int first = 0;
	for (int i = 0; i < n; ++i)
		if (d1[i] < 0)
			continue;
		else if (d2[i] < 0)
			++first;
		else if (d1[i] <= d2[i])
			++first;

	if (first > n - first)
		std::cout << "Fennec" << std::endl;
	else
		std::cout << "Snuke" << std::endl;
	return 0;
}
