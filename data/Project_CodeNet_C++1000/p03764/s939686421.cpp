#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <numeric>
#include <math.h>
#include <algorithm>
#include <functional>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <complex>
#include <bitset>
#define full(c) c.begin(), c.end()
#define vector2d(name,type,h,w,init) vector<vector<type>> name(h,vector<type>(w,init)) 
const int PRIME = 1000000007;
const int INT_INF = 2147483647;
const long long int LL_INF = 9223372036854775807;
const double PI = acos(-1);
const double EPS = 0.000000001;
typedef unsigned long long int ull;
typedef long long int ll;
using namespace std;

int main() {
	ll i, n, m, A = 0, B = 0;
	cin >> n >> m;
	vector<ll> a(n);
	vector<ll> b(m);
	vector<ll> as(n);
	vector<ll> bs(m);
	cin >> a[0];
	as[0] = a[0];
	for (i = 1; i < n; i++) {
		cin >> a[i];
		as[i] = a[i] + as[i - 1];
	}
	cin >> b[0];
	bs[0] = b[0];
	for (i = 1; i < m; i++) {
		cin >> b[i];
		bs[i] = b[i] + bs[i - 1];
	}
	for (i = 0; i < n; i++) {
		A += (i + 1) * a[i] - as[i];
		A %= PRIME;
	}
	for (i = 0; i < m; i++) {
		B += (i + 1) * b[i] - bs[i];
		B %= PRIME;
	}
	cout << (A * B) % PRIME << endl;
	return 0;
}