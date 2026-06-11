#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <limits>

template<class T>
using matrix = std::vector<std::vector<T>>;
using usize = std::size_t;
using isize = std::ptrdiff_t;

constexpr usize word = 26;
constexpr usize infty = std::numeric_limits<usize>::max();

matrix<usize> make_index (const std::string &s) {
	const usize n = s.length();
	matrix<usize> index(n + 1, std::vector<usize>(word, n + 1));
	for (usize i = n; i > 0; i--) {
		index[i - 1] = index[i];
		index[i - 1][s[i - 1] - 'a'] = i - 1;
	}
	return index;
}

template<class T>
bool chmin (T &a, const T &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
	std::string s;
	std::cin >> s;
	const usize n = s.length();
	auto index = make_index(s);
	
	std::vector<usize> dp(n + 1, infty);
	std::vector<char> ch(n + 1, 'a');
	dp[n] = 1;
	
	for (usize i = n; i > 0; i--) {
		for (usize j = 0; j < word; j++) {
			const char c = ('a' + j);
			if (index[i - 1][j] == n + 1) {
				if (chmin<usize>(dp[i - 1], 1)) ch[i - 1] = c;
			} else if (chmin(dp[i - 1], dp[index[i - 1][j] + 1] + 1)) {
				ch[i - 1] = c;
			}
		}
	}

	usize i = 0;
	std::string ans = "";
	while (i <= n) {
		ans += ch[i];
		i = index[i][ch[i] - 'a'] + 1;
	}
	
	std::cout << ans << '\n';

	return 0;
}