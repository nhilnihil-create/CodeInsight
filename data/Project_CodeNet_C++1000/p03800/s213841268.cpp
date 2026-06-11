#include <bits/stdc++.h>
using namespace std;

int main()
{
	auto check = [](bool same, char l, char r) {
		return same == (l == r);
	};

	int n;
	string s;
	cin >> n >> s;

	for (int fst = 0; fst < 2; fst++)
	{
		for (int snd = 0; snd < 2; snd++)
		{
			string ans(n, ' ');
			ans[0] = "WS"[fst];
			ans[1] = "WS"[snd];

			for (int i = 1; i < n - 1; i++)
			{
				ans[i + 1] = "WS"[((ans[i] == 'S') == (s[i] == 'o')) == (ans[i - 1] == 'S')];
			}

			if (check(((ans[n - 1] == 'S') == (s[n - 1] == 'o')), ans[0], ans[n - 2]) && check(((ans[0] == 'S') == (s[0] == 'o')), ans[1], ans[n - 1]))
			{
				cout << ans << endl;
				return 0;
			}
		}
	}

	cout << -1 << endl;

	return 0;
}