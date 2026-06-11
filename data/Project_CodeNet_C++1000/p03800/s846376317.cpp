#include <bits/stdc++.h>

using ll = long long;
constexpr ll inf = static_cast<ll>(1e17);
constexpr ll mod = static_cast<ll>(1e9 + 7);

int n;
std::string s;
int main()
{
	std::cin >> n >> s;

	std::string s1[] = { "S","W" };
	std::string s2[] = { "S","W" };

	std::string ans = "-1";
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j) {
			std::string res;

			res = s1[i] + s2[j];
			for (int k = 1, end = n - 1; k < end; ++k)
				if (res[k] == 'S' ? s[k] == 'o' : s[k] == 'x')
					res += res[k - 1];
				else
					res += (res[k - 1] == 'S' ? 'W' : 'S');
			int r1 = (res[1] == res[n - 1] ? 1 : -1);
			int r2 = (res[0] == res[n - 2] ? 1 : -1);
			int r3 = (res[0] == 'S' ? 1 : -1);
			int r4 = (res[n - 1] == 'S' ? 1 : -1);
			int r5 = (s[0] == 'o' ? 1 : -1);
			int r6 = (s[n - 1] == 'o' ? 1 : -1);
			if (r1*r3*r5 == 1 && r2*r4*r6 == 1) {
				ans = res;
				break;
			}
		}

	std::cout << ans << std::endl;
	return 0;
}
