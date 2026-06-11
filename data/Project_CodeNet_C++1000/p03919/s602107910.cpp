#include <cstdio>
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define RREP(i, n) for(ll i = n - 1; i >= 0; i--)
#define REP2(i, n, k) for(ll i = 0; i < n; i += k)




int main() {
	int h, w;
	cin >> h >> w;
	REP(i, h) {
		REP(j, w) {
			string s;
			cin >> s;
			if (s == "snuke") {
				cout << (char)('A' + j) << i + 1 << endl;
				return 0;
			}
		}
	}
}