#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
const long long MOD = 1000000007;
using namespace std;
typedef long long ll;

map<ll, int> mp;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int m = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (m < a) {
			m = a;
			ans = a + b;
		}
	}
	cout << ans << endl;
 	return 0;
}