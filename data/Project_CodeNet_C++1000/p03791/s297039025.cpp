
#if 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>

#define in std::cin
#define out std::cout

constexpr uint64_t MOD = 1'000'000'007;
int32_t N;
int32_t X[100000];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	//入力
	in >> N;
	for (int32_t i = 0; i < N; ++i)
	{
		in >> X[i];
	}

	uint64_t result = 1;//答えの通り数
	int32_t num_ON = 0;//既に数直線上においてあるロボットの個数
	//全てを奇数座標に
	for (int32_t i = 0; i < N; ++i)
	{
		++num_ON;
		auto standable = (X[i] + 1) / 2;//数直線上の奇数座標の数
		if (standable < num_ON) {
			//埋まっている=>どれかをゴールさせる
			result *= num_ON;
			result %= MOD;
			--num_ON;
		}
	}
	//残りを好きな順番でゴールさせる
	do{
		result *= num_ON;
		result %= MOD;
	}while (--num_ON);
	out << result << std::endl;

	return 0;
}
#endif