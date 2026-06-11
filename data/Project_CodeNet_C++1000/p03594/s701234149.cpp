#include <iostream>
#include <array>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include <queue>
#include <iomanip>
#include <functional>
#include <climits>

using namespace std;

using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = std::vector<ll>;
using vpll = std::vector<pll>;
using vpii = std::vector<pii>;
using vi = std::vector<int>;
using vvi = std::vector<vi>;

const ll mod197 = 1000000007LL;
const ll INF = 200LL * 200 * 100000 + 10;

const double PI11 = 3.14159265359;

// (a ^ b) % mod
ll powMod(ll x, ll k, ll m) {
	if (k == 0)     return 1;
	if (k % 2 == 0) return powMod(x*x % m, k / 2, m);
	else            return x*powMod(x, k - 1, m) % m;
}

int main() {

	int h, w, d;
	cin >> h >> w >> d;

	char arr[2][2] = {'R','Y','G','B'};

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			//cout << i + j << " " << i - j + w << endl;

			cout << arr[(i + j)/d % 2][(i - j + w)/d % 2];

		}
		cout << endl;
	}


	return 0;
}

