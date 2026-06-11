// Solution of official editorial

#include<algorithm>
#include<cstdio>
#include<functional>

static char ibuf[1<<20|1], *p1 = ibuf, *p2 = ibuf;

struct IO {
	inline char gc() {
		return p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 20 | 1, stdin), p1 == p2) ? EOF : *p1++;
	}

	template<typename T>
	inline IO operator>>(T &n) {
		n = 0; bool s = 0; char c = gc();
		while (c < '0' || c > '9') s |= c == '-', c = gc();
		while (c >= '0' && c <= '9') n = n * 10 + (c ^ 48), c = gc();
		if (s) n = -n;
		return *this;
	}
} cin;

int N, z[500003];

bool solve() {
	for (int i = 1; i <= N; ++i)
		if (z[i + 1] < i + 1) {
			int j = i;
			while (z[j + 1] >= i) ++j;
			return ((z[i] - i) | (j - i)) & 1;
		}
	return 0;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> z[i];
	std::sort(z + 1, z + N + 1, std::greater<int>());

	puts(solve() ? "First" : "Second");
	return 0;
}

