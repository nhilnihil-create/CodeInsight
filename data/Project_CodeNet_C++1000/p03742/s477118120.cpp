#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <functional>
using namespace std;

typedef long long ll;
int main() {
	ll x, y; cin >> x >> y;
	cout << (abs(x - y) > 1 ? "Alice" : "Brown") << endl;
	return 0;
}