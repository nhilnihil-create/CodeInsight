#include <bits/stdc++.h>

std::vector<bool> isSheep;

bool solve();

int main()
{
	if (!solve()) puts("-1");
	else
	{
		for (const auto& e: isSheep)
			if (e) putchar('S');
			else putchar('W');
		putchar('\n');
	}
	
	return 0;
}

bool solve()
{
	int N;
	scanf("%d", &N);
	std::string s;
	std::cin >> s;
	isSheep.resize(N);
	for (int first{}; first < 2; first++)
		for (int second{}; second < 2; second++)
		{
			isSheep[0] = first == 1;
			isSheep[1] = second == 1;
			for (int i{1}; i < N - 1; i++)
				if (isSheep[i]) isSheep[i + 1] = isSheep[i - 1] ^ (s[i] == 'x');
				else isSheep[i + 1] = isSheep[i - 1] ^ (s[i] == 'o');
			int num{};
			if (isSheep[N - 2]) num++;
			if (isSheep[N - 1]) num++;
			if (isSheep[0]) num++;
			if ((num % 2 == 1) ^ (s[N - 1] == 'o'))
				continue;
			num = 0;
			if (isSheep[N - 1]) num++;
			if (isSheep[0]) num++;
			if (isSheep[1]) num++;
			if ((num % 2 == 1) ^ (s[0] == 'o'))
				continue;
			return true;
		}
	return false;
}