#include<iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include<math.h>
#include <assert.h>
#include<bitset>
#include<string>
#include <deque>
#include<queue>
#include <iomanip>
#include<map>
#include <random>
#include<type_traits>
#include<stack>
#include <sstream> 
#include <limits>
#include <numeric>
#include<string.h>
#include<set>
#include <climits>
using namespace std;
typedef unsigned long long ull;
#define ll long long int
static const double PI = 3.141592653589793;
const ll INF = 100000000000000;
ll mod = 1000000007;
//typedef vector<int> V;
//typedef vector<V> VV;
//typedef vector<VV> VVV;

int main() {
	ll n, a[100005], y1 = 0, y2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll s = 0;
	for (int i = 0; i < n; i++) {
		s += a[i];
		if (i % 2 == 0) {
			if (s <= 0) {
				y1 += abs(s) + 1;
				s = 1;
			}
		}
		else {
			if (s >= 0) {
				y1 += s + 1;
				s = -1;
			}
		}
	}
	s = 0;
	for (int i = 0; i < n; i++) {
		s += a[i];
		if (i % 2 == 0) {
			if (s >= 0) {
				y2 += s + 1;
				s = -1;
			}
		}
		else {
			if (s <= 0) {
				y2 += abs(s) + 1;
				s = 1;
			}
		}
	}
	cout << min(y1, y2) << endl;
	return 0;
}