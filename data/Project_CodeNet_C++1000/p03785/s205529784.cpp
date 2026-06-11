/*
このコード、と～おれ!
Be accepted!
∧＿∧　
（｡･ω･｡)つ━☆・*。
⊂　　 ノ 　　　・゜+.
　しーＪ　　　°。+ *´¨)
 　　　　　　　　　.· ´¸.·*´¨) ¸.·*¨)
			　　　　　　　　　　(¸.·´ (¸.·'* ☆
					*/

#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <climits>
#include <tuple>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <memory>
#include <iomanip>

#define rep(i, n) for(Int (i) = 0; (i) < (n); ++(i))
#define debug(var) std::cout << #var << ": " << var << "\n"
using Int = int64_t;
constexpr Int INF = INT_MAX;
constexpr Int mod = 1e9 + 7;

//a, a + 1, a + 2, ... , b - 1, bの総和を求める関数(a <= b)。計算量はO(1)
Int Sum(Int a, Int b) {
	if (b < a)return 0;
	if ((b - a + 1) % 2 == 0)return (a + b) * (b - a + 1) / 2;
	else return (a + b) * ((b - a + 1) / 2) + (a + b) / 2;
}

void calc() {

	Int N, C, K; std::cin >> N >> C >> K;
	std::vector<Int> T(N);
	rep(i, N)std::cin >> T[i];
	std::sort(T.begin(), T.end());
	Int ans = 0;
	Int num = 1;
	Int fir = 0; //最初の乗客
	for (Int i = 1; i < N; ++i) {
		if (T[i] <= T[fir] + K && num + 1 <= C) {
			num++;
		}
		else {
			ans++;
			fir = i;
			num = 1;
		}
	}
	ans++;

	std::cout << ans;

}


int main() {

	calc();

	return 0;
}