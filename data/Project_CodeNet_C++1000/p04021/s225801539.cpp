#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <iomanip>
#include <tuple>
#include <functional>
#include <bitset>
#define INF 1000000009
#define LINF 1000000000000000009
#define double long double
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
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> b(n);
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
		mp[b[i]]++;
	}
	sort(all(b));
	for (int i = 0; i < n - 1; i++) {
		mp[b[i + 1]] += mp[b[i]];
	}
	for (int i = 0; i < n; i++) a[i] = mp[a[i]];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == i % 2) cnt++;
	}
	cout << cnt / 2 << endl;
}