#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
vector<pair<int, int>> vec;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.emplace_back(make_pair(a, b));
	}
	sort(vec.begin(), vec.end());
	long long ans = vec[n - 1].first + vec[n - 1].second;
	cout << ans << endl;
	return 0;
}