# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <unordered_map>
constexpr int MOD = 1000000000 + 7;
constexpr int INF = 2000000000;
using namespace std;
using LL = long long;

int main() {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1;; i++) {
		sum += i;
		if (sum >= n) {
			int pos = i;
			while (n != 0) {
				if (n >= pos) {
					cout << pos << endl;
					n -= pos;
				}
				pos--;
			}
			break;
		}
	}
}