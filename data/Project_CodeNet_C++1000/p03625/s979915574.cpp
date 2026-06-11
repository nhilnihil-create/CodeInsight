#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647

int main() {
	int N;
	cin >> N;
	map<int, int> mp;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		mp[a]++;
	}

	vector<long long > vec;
	for (auto iter = --mp.end(); iter != --mp.begin(); --iter) {
		if (2 <= iter->second) {
			vec.push_back(iter->first);
			iter->second -= 2;
			++iter;
		}

		if (vec.size() == 2) {
			break;
		}
	}

	if (vec.size() < 2) {
		cout << 0 << endl;
	}
	else {
		cout << vec[0] * vec[1] << endl;
	}
	return 0;
}