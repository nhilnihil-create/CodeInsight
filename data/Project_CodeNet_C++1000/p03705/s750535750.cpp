#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i,n) for(ll i = 0; i < n; i++)

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	if (a > b) {
		cout << 0 << endl;
		return 0;
	}
	if (n == 1) {
		if (a == b) {
			cout << 1 << endl;
			return 0;
		}
		cout << 0 << endl;
		return 0;
	}
	ll min = a * (n - 1) + b;
	ll max = b * (n - 1) + a;
	cout << max - min + 1 << endl;
}