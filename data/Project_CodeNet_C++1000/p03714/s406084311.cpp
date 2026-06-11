#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define INF 1145141919364364
#define all(vec) vec.begin(),vec.end()
#define ggr getchar(); getchar();return 0;
#define ll long long
#define P pair<int,int>
#define S second
#define F first
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0)return false;
	}
	return true;
}

int kai(int x) {
	if (x == 1)return 1;
	return kai(x - 1)*x;
}

int mod_pow(int x, int y, int moder) {
	int res = 1;
	while (y > 0) {
		if (y & 1)res = res * x%moder;
		x = x * x%moder;
		y >>= 1;
	}
	return res;
}

int n, a[364364];
priority_queue<int> que2;
priority_queue <int, vector<int>, greater<int>> que;
int ta;
vector<int> cnt, cnt2;


signed main() {
	cin >> n;
	rep(i, 3 * n)cin >> a[i];
	rep(i, n) {
		que.push(a[i]);
		ta += a[i];
	}
	cnt.push_back(ta);
	for (int i = n; i < 2 * n; i++) {
		if (que.top() < a[i]) {
			ta += a[i] - que.top();
			que.pop();
			que.push(a[i]);
		}
		cnt.push_back(ta);
	}
	ta = 0;
	for (int i = 3 * n - 1; i >= 2 * n; i--) {
		que2.push(a[i]);
		ta += a[i];
	}
	cnt2.push_back(ta);
	for (int i = 2 * n - 1; i >= n; i--) {
		if (que2.top() > a[i]) {
			ta -= que2.top() - a[i];
			que2.pop();
			que2.push(a[i]);
		}
		cnt2.push_back(ta);
	}
	int ans = -INF;
	rep(i, cnt.size()) {
		ans = max(ans, cnt[i] - cnt2[cnt.size() - 1 - i]);
	}
	cout << ans << endl;
}