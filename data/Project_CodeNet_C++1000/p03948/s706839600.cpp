#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fst first
#define snd second
const ll mod = 1000000007;
const ll INF = (1LL << 59);
const double dINF = 1000000000000000000.0;

int main(){
	int n, t; cin >> n >> t;
	ll a[100010];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll tmp_min=INF;
	ll sa=-INF;
	for (int i = 0; i < n; i++) {
		if (a[i] - tmp_min > sa)sa = a[i] - tmp_min;
		if (a[i] < tmp_min)tmp_min = a[i];
	}
	int ans = 0;
	tmp_min = INF;
	for (int i = 0; i < n; i++) {
		if (a[i] - tmp_min == sa)ans++;
		if (a[i] < tmp_min)tmp_min = a[i];
	}

	cout << ans << endl;
	return 0;
}