#include <iostream>
#include <iomanip>
#include <fstream>
#include <utility>
#include <queue>
#include <vector>
#include <array>
#include <stack>
#include <list>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define bs(n) (1ull<<(n))

constexpr ll inf = INT64_MAX / 4;

int main() {
	ll n, m, a[2000], b[2000], c[2000], d[1001], t;
	cin >> n >> m;
	rep(i, m)cin >> a[i] >> b[i] >> c[i];
	for (int i = 0; i < 1001; i++)d[i] = -inf;
	d[1] = 0;
	for (int i = 0; i <= 2*n; i++) {
		for (int j = 0; j < m; j++) {
			if (d[a[j]] != -inf && d[b[j]] < d[a[j]] + c[j]) {
				d[b[j]] = d[a[j]] + c[j];
			}
		}
		if (i == n - 1) t = d[n];
	}
	if (d[n] != t) cout << "inf";
	else cout << d[n];
	cout << endl;
}