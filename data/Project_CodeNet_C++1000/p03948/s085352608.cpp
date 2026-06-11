
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
#define INF 1e8
#define PI acos(-1)
typedef long long ll;
typedef pair<int, int> p_ii;


int main() {
	
	int i, n, t; cin >> n >> t;
	vector<int> a(n);
	for (i = 0; i < n; i++)cin >> a[i];
	priority_queue<int> que;
	set<int> check;
	for (i = 0; i < n; i++)que.push(a[i]);

	int ans = 1, benefit=-INF;
	for (i = 0; i < n-1; i++) {
		check.insert(a[i]);
		while (check.count(que.top()) != 0)que.pop();
		int btown = que.top();
		if (btown - a[i] > benefit) {
			benefit = btown - a[i];
			ans = 1;
		}
		else if (btown - a[i] == benefit) ans++;
	}

	cout << ans << endl;

	return 0;
}