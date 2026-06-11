
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007; //998244353;

template<class _T> static void get(_T& a) {
	std::cin >> a;
}
template<class _T> static void get(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void get(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}
template <class _T> static _T tp_pow(int base, int exp)
{
	_T ans = 1;

	for (int i = 0; i < exp; i++) {
		ans *= (_T)base;
	}
	return ans;
}

static void D();

int main()
{
	D();
	fflush(stdout);
	return 0;
}

static void D()
{
	int H, W;
	get(H, W);

	std::vector<std::string> grid(H);
	for (int i = 0; i < H; i++) {
		get(grid[i]);
	}
	
	int g1 = 0, g2 = 0, g4 = (H / 2) * (W / 2);
	if (H % 2 && W % 2) {
		g1 = 1;
		g2 = H / 2 + W / 2;
	}
	else if (H % 2) {
		g2 = W / 2;
	}
	else if (W % 2) {
		g2 = H / 2;
	}

	std::vector<int> ch(26, 0);
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			ch[grid[h][w] - 'a']++;
		}
	}

	int surp = 0;
	for (int i = 0; i < 26; i++) {
		surp = ch[i] % 4;
		if (surp % 2 && g1) {
			ch[i]--;
			g1--;
		}
	}

	for (int i = 0; i < 26; i++) {
		surp = ch[i] % 4;
		if (surp == 2 && g2) {
			ch[i] -= 2;
			g2--;
		}
	}

	if (g2 / 2) {
		g4 += g2 / 2;
		g2 -= (g2 / 2) * 2;
	}
	for (int i = 0; i < 26; i++) {
		surp = ch[i] % 4;
		if (!surp && ch[i] && g4) {
			g4 -= ch[i] / 4;
			ch[i] = 0;
		}
	}
	if (g1 || g2 || g4) {
		printf("No\n");
		return;
	}
	for (int i = 0; i < 26; i++) {
		if (ch[i]) {
			printf("No\n");
			return;
		}
	}
	printf("Yes\n");
}

