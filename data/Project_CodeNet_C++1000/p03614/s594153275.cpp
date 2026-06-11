
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
#define INF 1e9
#define PI acos(-1)
typedef long long ll;
typedef pair<int, int> p_ii;



int main() {
	
	int n; cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++)cin >> p[i];

	int ans = 0, pos = 0;

	while (pos < n) {
		if (p[pos] == pos + 1) {
			if (p[pos + 1]==pos+2) {
				ans++;
				pos += 2;
			}
			else {
				ans++;
				pos++;
			}
		}
		else pos++;
	}

	cout << ans << endl;
	
	return 0;
}