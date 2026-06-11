#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<stack>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

ll INF = 1e9 + 7;

ll n, m;

bool calc(ll x) {
	if (n >= x) {
		if (m >= 2 * x) return true;
		else return false;
	}
	else {
		ll k = x - n;
		if (m >= (2*x+2*k)) return true;
		else return false;
	}
}

int main() {
	cin >> n >> m;
	ll l = 0, r = 1e12;
	while (r - l > 1) {
		if (calc((l + r) / 2)) l = (l + r) / 2;
		else r = (l + r) / 2;
	}
	cout << l << endl;
}