#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>

#define FOR(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define IFOR(i, a, b) for(int (i)=(a);(i)<=(b);(i)++)
#define RFOR(i, a, b) for(int (i)=(a);(i)>=(b);(i)--)

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<int, int> num;
	FOR(i, 0, n) {
		int tmp;
		cin >> tmp;
		num[tmp]++;
	}

	vector<int> mod(m, 0);
	vector<int> odd(m, 0);
	for (auto t : num) {
		mod[t.first%m] += t.second;
		if (t.second % 2) {
			odd[t.first%m]++;
		}

	}
	int cnt = 0;
	FOR(i, 0, m) {
		if (i == 0 || i * 2 == m)
			continue;
		int toadd = min(mod[i], mod[(m - i) % m]);
		cnt += toadd;
		odd[i] -= toadd, odd[(m - i) % m] -= toadd;
		mod[i] -= toadd, mod[(m - i) % m] -= toadd;
	}
	FOR(i, 0, m) {
		if (i == 0 || i * 2 == m) {
			cnt += mod[i] / 2;
		}
		else {
			if (odd[i] <= 0) {
				cnt += mod[i] / 2;
			}
			else {
				cnt += (mod[i] - odd[i]) / 2;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}