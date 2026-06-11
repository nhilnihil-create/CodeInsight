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

	int n;
	cin >> n;
	vector<int> a(n);
	int odd_cnt = 0;
	int four_cnt = 0;
	rep(i, n) {
		cin >> a.at(i);
		if (a.at(i) % 2 != 0) {
			odd_cnt++;
		}
		else if (a.at(i) % 4 == 0) {
			four_cnt++;
		}
	}

	if (four_cnt >= odd_cnt) {
		cout << "Yes" << endl;
	}
	else if (n % 2 != 0 && (odd_cnt - four_cnt) == 1 && (odd_cnt + four_cnt) == n) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	
	return 0;
	
}

