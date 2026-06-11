#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int k, s;
	cin >> k >> s;
	long long int res = 0;
	for (int i = 0; i <= k; i++) {
		if (k + k + i < s) continue;
		if (i > s) continue;
		int l = max(s - i - k, 0);
		int h = min(k, s - i);
		if (l > h) continue;
		res += h - l + 1;
	}
	cout << res << endl;
}
