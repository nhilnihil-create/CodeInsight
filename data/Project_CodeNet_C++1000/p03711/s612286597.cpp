#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <queue>
#include <map>
#include <cstdint>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const long long mod = 1000000007;
typedef long long int ll;
typedef pair<ll, ll> P;
const vector<int> di = { -1, 0, 1, 0 };
const vector<int> dj = { 0, 1, 0, -1 };



int main() {

	int x, y;
	cin >> x >> y;

	int d[7] = { 1, 3, 5, 7, 8, 10, 12 };
	int e[4] = { 4, 6, 9, 11 };

	int a, b;
	a = 0;
	b = 0;
	rep(i, 7) {
		if (d[i] == x) {
			a = 1;
		}
		if (d[i] == y) {
			b = 1;
		}
	}
	rep(i, 4) {
		if (e[i] == x) {
			a = 2;
		}
		if (e[i] == y) {
			b = 2;
		}
	}
	if (a == b) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	

	return 0;
}

