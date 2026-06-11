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
#include <type_traits>

#define rep(i, n) for(Int (i) = 0; (i) < (n); ++(i))
#define all(n) std::begin(n), std::end(n)
#define debug(var) std::cout << #var << ": " << var << "\n"
using Int = int64_t;
constexpr Int INF = INT_MAX;
constexpr Int mod = 1e9 + 7;


void calc() {

	Int a, b, c; std::cin >> a >> b >> c;
	if (a + b == c || b + c == a || c + a == b)std::cout << "Yes";
	else std::cout << "No";
	
}


int main() {

	calc();

	return 0;
}