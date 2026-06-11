#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <stdio.h>
#include <vector>
#define int long long
#define endre getchar();getchar();return 0
#define moder 1e9+7
#define inf 1e18
#define rep(i,n) for(int i=0;i<n;i++)
#define P pair<int,int>
#define all(v) v.begin(),v.end()
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())
using namespace std;
bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}
int mod_pow(int x, int y, int mod) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x%mod;
		}
		x = x * x%mod;
		y >>= 1;
	}
	return res;
}

/*--------Library Zone!--------*/

int n, t, ma, memo;
int a[100005];
set<int>st;
signed main() {
	cin >> n >> t;
	rep(i, n) {
		cin >> a[i];
		st.insert(a[i]);
	}
	rep(i, n - 1) {
		st.erase(a[i]);
		set<int>::reverse_iterator j = st.rbegin();
		if (*j - a[i] > ma) {
			ma = *j - a[i];
			memo = 1;
		}
		else if (ma == *j - a[i]) {
			memo++;
		}
	}
	cout << memo << endl;
	endre;
}
