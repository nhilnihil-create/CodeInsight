
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007;

template<class _T> static void getint(_T& a) {
	std::cin >> a;
}
template<class _T> static void getint(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}

static void AGC018B();

int main()
{
	AGC018B();
	fflush(stdout);
	return 0;
}

static void AGC018B()
{
	int N, M;
	getint(N, M);

	std::vector<std::vector<int>> likes(N, std::vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			getint(likes[i][j]);
		}
	}

	int ans = 1000;
	while (likes[0].size()) {
		std::map<int, int> count;
		for (int i = 0; i < N; i++) {
			count[likes[i][0]]++;
		}

		int maxPeople = 0;
		int target = -1;
		for (auto it = count.begin(); it != count.end(); it++) {
			if (it->second > maxPeople) {
				maxPeople = it->second;
				target = it->first;
			}
		}
		ans = std::min(ans, maxPeople);

		for (int i = 0; i < N; i++) {
			for (auto it = likes[i].begin(); it != likes[i].end(); it++) {
				if (*it == target) {
					likes[i].erase(it);
					break;
				}
			}
		}
	}
	printf("%d\n", ans);
}