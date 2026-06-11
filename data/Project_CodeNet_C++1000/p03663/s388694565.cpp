#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <cctype>
#include <cassert>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,b,e) for(int i = (b); i <= (e); i++)
#define INF (1001001001)
#define EPS (1e-15)

#define pr(x) do{cout << (#x) << " = " << (x) << endl;}while(0)
#define pri(x,i) do{cout << (#x) << "[" << i << "] = " << (x[i]) << endl;}while(0)
#define pra(x,n) rep(__i,n) pri(x,__i);
#define prar(x,b,e) repr(__i,b,e) pri(x,__i);

typedef long long ll;
typedef pair<int, int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;

ll MOD = 1000000007;

int in() {
	int a;
	scanf("%d ", &a);
	return a;
}

bool query(ll q) {
	cout << "? " << q << endl;
	string s;
	cin >> s;
	return s == "Y";
}

void FA(int ans) {
	cout << "! " << ans << endl;
	exit(0);
}

int main() {
	ll ans = 0;
	bool tenbeki = true;
	for (;;) {
		int left = -1;
		int right = 9;
		// (left, right]
		while (right - left > 1) {
			if (ans == 0 && right == 1) break;
	// pr(left);
	// pr(right);
			int mid = (right + left) / 2;
			ll temp = ans * 10 + mid;
			while (temp < MOD) temp = temp * 10 + 9;
			bool q = query(temp);
			if (q) right = mid;
			else left = mid;
		}
		if (right > 1 || ans > 0 && right != 0) tenbeki = false;
		if (right == 0) {
			if (query(ans * 10 - 1) ^ !tenbeki) {
				FA(ans);
			}
		}
		ans = ans * 10 + right;
	}
	return 0;
}
