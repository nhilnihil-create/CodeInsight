#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <bitset>
#include <memory>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>
#include <algorithm>
#include <random>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < 2 * n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	int res = 0;
	for (int i = 0; i < 2 * n; i += 2) {
		res += v[i];
	}
	cout << res << endl;
}







