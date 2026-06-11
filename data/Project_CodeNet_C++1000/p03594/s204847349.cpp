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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr long long MOD = 1000000000 + 7;
constexpr long long INF = 100000000000000;
const double PI = acos(-1);

string s = "RYGB";

int main() {
	int h, w, d;
	cin >> h >> w >> d;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int x = i - j;
			int y = i + j;
			cout << s[(y + 514 * d) % (2 * d) / d * 2 + (x + 514 * d) % (2 * d) / d];
		}
		cout << endl;
	}
}