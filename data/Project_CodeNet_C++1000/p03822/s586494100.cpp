#if 1
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <set>
#include <numeric>
#include <cassert>

using namespace std;
#define int long long
#define uint unsigned long long
constexpr int MOD = 1000000007;
constexpr int INF = 1145141919810;

#define LOADVEC(type,name,N) std::vector<type>name(N); \
for (int nnn = 0; nnn < N; ++nnn) { \
	cin >> name[nnn]; \
}

#define LOADVEC2(type,name0,name1,N) std::vector<type>name0(N),name1(N); \
for (int nnn = 0; nnn < N; ++nnn) { \
	cin >> name0[nnn];cin >> name1[nnn]; \
}

#define LOAD(type,name) type name; \
cin >> name;


void proc();

signed main() {
	ios::sync_with_stdio(false);
	proc();
	return 0;
}

/*
--------------------------------------------------------
--------------------------------------------------------
---------------    template      ----------------------
--------------------------------------------------------
--------------------------------------------------------
*/

void proc() {
	LOAD(int, N);
	LOADVEC(int, a, N - 1);
	std::vector<unordered_set<int>>childs(N);
	std::vector<unordered_set<int>>childs2;
	std::vector<int> depth(N, -1);
	std::vector<int>stack;
	for (int i = 0; i < N - 1; ++i) {
		childs[a[i] - 1].insert(1 + i);
	}
	childs2 = childs;
	//
	stack.reserve(N + 1);
	stack.push_back(0);
	depth[0] = -2;
	while (!stack.empty()) {
		int v = stack.back();
		bool pushed = false;
		for (auto child : childs2[v]) {
			if (depth[child] == -1) {
				depth[child] = -2;
				stack.push_back(child);
				childs2[v].erase(child);
				pushed = true;
				break;
			}
		}
		if (!pushed) {
			std::vector<int>childsDepth;
			childsDepth.reserve(childs[v].size());
			for (auto &child : childs[v]) {
				childsDepth.push_back(depth[child]);
			}
			std::sort(childsDepth.begin(), childsDepth.end(), std::greater<int>());
			//
			int maxDepth = 0;
			for (int i = 0; i < childsDepth.size(); ++i) {
				int oneDepth = childsDepth[i] + i + 1;
				if (maxDepth < oneDepth)maxDepth = oneDepth;
			}
			depth[v] = maxDepth;
			stack.pop_back();
		}
	}
	cout << depth[0];
}

#endif
