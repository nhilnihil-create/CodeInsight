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
	int k,s;
	cin >> k >> s;
	int count = 0;
	rep(x, k + 1) {
		rep(y, k + 1) {
			int z = s - x - y;
			if (z >= 0 && z <= k) {
				count ++;
			}
		}
	}
	cout << count << endl;



	return 0;
}
