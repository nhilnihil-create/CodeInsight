#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	int people;
	int total=0;

	for (int i = 0; i < N; i++) {

		int l, r;
		cin >> l >> r;
		people = r - l + 1;
		total += people;

	}

	cout << total << endl;

	
}


