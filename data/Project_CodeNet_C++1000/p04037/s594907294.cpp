#include <bits/stdc++.h>

bool solve();

int main()
{
	if (solve()) puts("First");
	else puts("Second");

	return 0;
}

bool solve()
{
	int N;
	scanf("%d", &N);
	std::vector<int> a(N);
	for (auto& e: a) scanf("%d", &e);
	std::sort(a.rbegin(), a.rend());
	a.push_back(0);
	for (auto& e: a) e--;
	int center{};
	while (center + 1 <= a[center + 1]) center++;
	// 後手が相手と逆のを選んだ場合の挙動
	if ((a[center] + center) % 2 == 0)	// centerが負けの場合
	{
		if (a[center + 1] < center) return false;	// 先手がcenter+1に行けない場合
		int count{};
		for (int i{center + 1}; i < N; i++)
			if (a[i] == a[center + 1])
				count++;
		if (count % 2 == 1) return true;
		return false;
	}
	else
	{
		if (center < a[center]) return true;
		if (center > 0 && (a[center - 1] + center) % 2 == 0) return true;
		return false;
	}
}