#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <new>
#include <typeinfo>
#include <iterator>

typedef long long ll;
typedef unsigned long long ull;
constexpr ll mop = 1000000007;
constexpr ll mop2 = 998244353;

using namespace std;

int main() {
	ll elementMax, elementSum;
	cin >> elementMax >> elementSum;
	ll ans = 0;
	for (ll x = 0; x <= elementMax; x++) {
		for (ll y = 0; y <= elementMax; y++) {
			ll z = elementSum - x - y;
			if (0 <= z && z <= elementMax) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}