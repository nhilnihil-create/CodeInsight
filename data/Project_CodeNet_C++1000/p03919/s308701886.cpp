#include <bits/stdc++.h>

int main()
{
	int H, W;
	scanf("%d%d", &H, &W);
	using vs = std::vector<std::string>;
	std::vector<vs> S(H, vs(W));
	for (auto& e: S)
		for (auto& f: e)
			std::cin >> f;
	for (int i{}; i < H; i++)
		for (int j{}; j < W; j++)
		{
			if (S[i][j] == "snuke")
			{
				printf("%c%d\n", 'A' + j, 1 + i);
				return 0;
			}
		}

	return 0;
}