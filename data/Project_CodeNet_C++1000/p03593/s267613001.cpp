#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>
#include <bitset>
#include <iomanip>
#include <limits>
#include <chrono>
#include <random>
#include <array>
#include <unordered_map>
#include <functional>
#include <complex>

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int inf = 1 << 28;
constexpr long long mod = 1000000007LL;
//constexpr long long mod = 998244353LL;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;


int main()
{
	/*
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	*/

	int H, W; scanf("%d %d", &H, &W);
	vector<int> cnt(26);
	for (int i = 0; i < H; i++) {
		string s; cin >> s;
		for (int j = 0; j < W; j++) cnt[s[j] - 'a']++;
	}
	if (H % 2 == 0 && W % 2 == 0) {
		for (int i = 0; i < 26; i++) {
			if (cnt[i] % 4 != 0) {
				puts("No");
				return 0;
			}
		}
		puts("Yes");
		return 0;
	}
	if (H % 2 == 0 || W % 2 == 0) {
		if (W % 2 == 0) swap(H, W);
		ll all = H * W;
		ll tmp = 0;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] % 4 == 2) tmp++;
			if (cnt[i] % 2) {
				puts("No");
				return 0;
			}
		}
		if (tmp > H / 2) puts("No");
		else puts("Yes");
	}
	else {
		int tmp = 0;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] % 2) {
				tmp++;
				cnt[i]--;
			}
		}
		if (tmp != 1) {
			puts("No");
			return 0;
		}
		tmp = 0;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] % 4 == 2) tmp++;
		}
		if (tmp > (H - 1) / 2 + (W - 1) / 2) puts("No");
		else puts("Yes");
	}
	return 0;
	/*
		おまじないを使ったらscanfとprintf関連注意！！！！！！！！！！！！
	*/
}
