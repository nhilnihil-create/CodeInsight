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
	int n;
	int m;
	cin >> n >> m;

	vector<int> vec(n+1,0);

	for (int i = 0; i < 2 * m; i++) {

		int x;
		cin >> x;

		vec.at(x)++;


	}

	for (int i = 1; i <= n; i++) {

		cout << vec.at(i) << endl;

	}




}
