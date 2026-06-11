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
#include <set>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const long long mod = 1000000007;
typedef long long int ll;
typedef pair<ll, ll> P;
const vector<int> di = { -1, 0, 1, 0 };
const vector<int> dj = { 0, 1, 0, -1 };
const double PI = 3.14159265358979323846;


int main() {
	ll n;
	cin >> n;
	map<ll, ll> a;
	rep(i, n) {
		ll num;
		cin >> num;
		a[num] = a[num] + 1;
	}
	ll max_len = 0;
	ll max_len_second = 0;
	for (auto p : a) {
		if (p.second > 1) {
			max_len_second = max_len;
			max_len = p.first;
		}
		if (p.second > 3) {
			max_len_second = max_len;
		}
	}
	cout << max_len * max_len_second << endl;
	
	return 0;
	
}

