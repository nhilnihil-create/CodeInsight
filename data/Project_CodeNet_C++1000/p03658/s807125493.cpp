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
const double PI = 3.14159265358979323846;

int main() {

	int n, k;
	cin >> n >> k;
	vector<int> l(n);
	rep(i, n) cin >> l.at(i);

	sort(l.begin(), l.end());
	reverse(l.begin(), l.end());
	int sum = 0;
	rep(i, k) {
		sum += l.at(i);
	}
	cout << sum << endl;
	return 0;
	
}

