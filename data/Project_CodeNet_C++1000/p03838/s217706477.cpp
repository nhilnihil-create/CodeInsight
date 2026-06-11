#include <sys/time.h>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <cctype>

using namespace std;

using ll = long long;
using P = pair<double, double>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
ll mod = 1000000007LL;



int main() {
	int x,y;
	cin >> x >> y;
	int cur = 1e9 * 2 + 100;
	//cout << cur << endl;

	// ex. x = 10, y = 20
	if (x <= y) {
		cur = min (y - x, cur);
	}

	if (-x <= y) {
		cur = min (y + x + 1, cur);
	}

	if(x <= -y) {
		cur = min (-y - x + 1, cur);
	}

	if (-x <= -y) {
		cur = min(-y + x + 2, cur);
	}

	cout << cur << endl;


	return 0;
}
