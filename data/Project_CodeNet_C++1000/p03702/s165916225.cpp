#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<queue>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int n, a, b;
ll h[maxn];

bool judge(ll mid) {
	ll midt = mid;
	for (int i = 1; i <= n; i++) {
		ll res = h[i] - mid * b;
		if (res <= 0) continue;
		midt -= res % (a - b) ? res / (a - b) + 1 : res / (a - b);
		if (midt < 0) return false;
	}
	return true;
}


int main() {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	ll low = 0, high = 1e9;
	while (high > low + 1) {
		ll mid = (low + high) / 2;
		if (judge(mid)) high = mid;
		else low = mid;
	}
	cout << high << endl;
}