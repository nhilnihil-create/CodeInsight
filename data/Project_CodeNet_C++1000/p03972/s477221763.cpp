#include <algorithm>
#include <cfloat>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod 1000000007
#define int long long
#define double long double
#define INF LLONG_MAX/1000
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int w, h, p, q;
signed main() {
	cin >> w >> h;
	prique<P, vector<P>, greater<P>> que;
	rep(i, w) {
		cin >> p;
		que.push(make_pair(p, 0));
	}
	rep(i, h) {
		cin >> q;
		que.push(make_pair(q, 1));
	}
	w++; h++;
	int ans = 0;
	while (!que.empty()) {
		P p = que.top();
		que.pop();
		if (p.second) {
			ans += p.first * w;
			h--;
		}
		else {
			ans += p.first * h;
			w--;
		}
	}
	cout << ans << endl;
	return 0;
}