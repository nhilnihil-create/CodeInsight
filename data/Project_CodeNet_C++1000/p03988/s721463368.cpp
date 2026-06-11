#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#define INF 1000000009
#define LINF 1000000000000000009
#define EPS 1e-10
#define PI 3.1415926535897932384626
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T> bool chmax(T &a, const T&b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T&b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(all(a));
	bool flag = true;
	if (a[n - 1] > a[0] * 2) flag = false;
	for (int i = a[n - 1] / 2 + 1; i <= a[n - 1]; i++) {
		if (mp[i] < 2) flag = false;
	}
	if (a[n - 1] % 2 == 0 && mp[a[n - 1] / 2] != 1) flag = false;
	if (a[n - 1] % 2 == 1 && mp[a[n - 1] / 2 + 1] != 2) flag = false;
	cout << (flag ? "Possible" : "Impossible") << endl;
} 