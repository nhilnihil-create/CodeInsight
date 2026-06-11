#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctype.h>
#include <map>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cctype>
#include <queue>
#include <set>
#include <list>
#define PI 3.141592653
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define DescSort(a) sort(a.begin(),a.end(),std::greater<int>())

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
	int n, t;
	cin >> n >> t;
	vector<ll> x(n);
	rep(i, 0, n)cin >> x[i];
	int ans = 0;
	rep(i, 1, n) {
		if (x[i-1] + t <= x[i]) ans += t;
		else {
			ans += x[i] - x[i - 1];
		}
	}
	ans += t;
	cout << ans << endl;
}