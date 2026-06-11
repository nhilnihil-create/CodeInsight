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

using namespace std;

using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
const int inf = 1e+9;



int main() {
	int n, m, k;
	cin >> n >> m >> k;
	rep (i, n + 1) {
		rep(j, m + 1) {
		  if (k == j * i + (n - i) * (m - j)) {
		  	cout << "Yes" << endl;
		  	return 0;
		  }
		}
	} 
	cout << "No" << endl;


	return 0;
}
