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
		int a;
		cin >> a;
		vec.emplace_back(make_pair(a, i));
	}
	sort(vec.begin(), vec.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 != vec[i].second % 2) {
			ans++;
		}
	}
	cout << ans / 2 << endl;
}
