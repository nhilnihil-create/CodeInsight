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
#define rep(i, n) for (ll i = 0; i < n; i++)
const long long mod = 1000000007;
typedef long long int ll;
typedef pair<int, int> P;
const vector<int> di = { -1, 0, 1, 0 };
const vector<int> dj = { 0, 1, 0, -1 };


int main() {

	int a, b;
	cin >> a >> b;

	int time = a + b;

	if (time < 24) {
		cout << time << endl;
	}
	else {
		cout << time - 24 << endl;
	}
	
	return 0;
}