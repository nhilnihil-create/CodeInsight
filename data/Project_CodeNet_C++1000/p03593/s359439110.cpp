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


using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);

	rep(i, h) {
		cin >> s[i];
	}

	vector<int> c(26,0);
	rep(i, h) {
		rep(j, w) {
			c[s[i][j] - 'a']++;
		}
	}
	int n4 = (w / 2) * (h / 2);
	int n1 = (w % 1 == 1 &&  h % 1 == 1) ? 1 : 0;
	int n2 = 0;
	if (w % 2) {
		n2 = h / 2;
	}
	if (h % 2) {
		n2 += w / 2;
	}


	rep(i, 26) {
		
		int cur4 = min(c[i] / 4, n4);
		n4 -= cur4;
		c[i] -= cur4 * 4;
		
		int cur2 = min(c[i] / 2, n2);
		n2 -= cur2;
		c[i] -= cur2 * 2;

		int cur1 = min(c[i], n1);
		n1 -= cur1;
		c[i] -= cur1 * 1;
	}

	if (n4 > 0 || n2 > 0 || n1 > 0) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}

	return 0;
}