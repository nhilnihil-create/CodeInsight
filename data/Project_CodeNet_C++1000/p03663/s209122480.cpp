#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

typedef long long ll;
const int pw10[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

inline bool query(ll x) {static char op[4]; return cout << '?' << ' ' << x << endl, cin >> op, *op == 89;}

inline int pow_of_ten() {
	for (int i = 0; i < 10; ++i) if (query(2 * pw10[i])) return pw10[i];
	return abort(), -1;
}

inline int answer(int x) {return cout << '!' << ' ' << x << endl, 0;}

int main() {
	int i, L, R, M;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	if (query(1000000000)) return answer(pow_of_ten());
	for (i = 1; i < 10 && query(pw10[i]); ++i);
	for (L = pw10[--i] + 1, R = pw10[i + 1] - 1; L < R; query((M = (L + R) / 2) * 10ll) ? R = M : L = M + 1);
	return answer(L);
}