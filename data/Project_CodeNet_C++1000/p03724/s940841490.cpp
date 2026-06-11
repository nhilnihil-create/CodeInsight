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


void calc() {

	Int N, M; std::cin >> N >> M;
	std::unordered_map<Int, Int> m;
	rep(i, M) {
		Int a, b; std::cin >> a >> b;
		m[a]++; m[b]++;
	}
	bool flag = true;
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		if (itr->second % 2 == 1)flag = false;
	}

	std::cout << (flag ? "YES" : "NO");

}


int main() {

	calc();

	return 0;
}