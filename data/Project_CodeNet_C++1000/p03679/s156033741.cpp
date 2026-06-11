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

	int x, a, b;
	cin >> x >> a >> b;

	if ((b - a) <= 0) {
		cout << "delicious" << endl;
	}
	else if (x >= (b - a)) {
		cout << "safe" << endl;
	}
	else {
		cout << "dangerous" << endl;
	}


	return 0;
}

