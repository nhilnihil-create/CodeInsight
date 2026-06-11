#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>

using namespace std;

int main() {
	int N; cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int a; cin >> a; v.push_back(a);
	}
	sort(v.begin(), v.end(), greater<int>());

	int length = v[0];

	int* count = new int[length + 1];
	for (int i = 0; i <= length; i++) {
		count[i] = 0;
	}
	for (auto itr = v.begin(); itr != v.end(); itr++) {
		count[*itr]++;
	}

	if (length % 2 == 0) {
		for (int i = length; i > length / 2; i--) {
			if (count[i] < 2) { cout << "Impossible" << endl; return 0; }
		}
		if (count[length / 2] != 1) { cout << "Impossible" << endl; return 0; }
	}
	else {
		for (int i = length; i * 2 > length + 2; i--) {
			if (count[i] < 2) { cout << "Impossible" << endl; return 0; }
		}
		if (count[(length + 1) / 2] != 2) { cout << "Impossible" << endl; return 0; }
	}

	cout << "Possible" << endl;
	return 0;
}