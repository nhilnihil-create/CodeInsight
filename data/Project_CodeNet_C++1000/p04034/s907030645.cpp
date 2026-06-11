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

	Int N, M; std::cin >> N >> M;
	std::vector<bool> exist(N, false);
	std::vector<Int> num(N, 1);
	exist[0] = true;

	rep(i, M) {
		Int x, y; std::cin >> x >> y; --x; --y;
		if (exist[x])exist[y] = true;
		--num[x]; ++num[y];
		if (num[x] == 0)exist[x] = false;
	}
	Int cnt = 0;
	rep(i, N) {
		if (exist[i])cnt++;
	}

	std::cout << cnt;

}


int main() {

	calc();

	return 0;
}