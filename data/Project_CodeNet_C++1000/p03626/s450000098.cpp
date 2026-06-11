#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <iomanip>
#include <string>
#include <queue>
#include <numeric>
#include <functional>
#include <array>
#include <map>
#include <set>

#define INF 1000000007 //1000000000000000003
#define MOD 1000000007

using namespace std;
using P = pair<int, int>;
using T = tuple<int, int, int>;

long long dp[100005][4];

bool compare_by_second(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {

	int N;
	cin >> N;

	string S1,S2;
	cin >> S1 >> S2;

	vector<bool>isVertical;
	for (int i = 0; i < N; ++i) {
		if (S1[i] == S2[i])isVertical.push_back(true);
		else {
			isVertical.push_back(false);
			++i;
		}
	}
	
	long long ans = 3;
	bool before = false;
	for (int i = 0; i < isVertical.size();++i) {
		long long num = 1;
		if (i == 0) {
			if (!isVertical[i])num *= 2;
		}
		else {
			if (isVertical[i]) {
				if (before) num *= 2;
			}
			else {
				if (before)num *= 2;
				else num *= 3;
			}
		}

		ans = (ans * num) % MOD;
		before = isVertical[i];
	}

	cout << ans << endl;
}
