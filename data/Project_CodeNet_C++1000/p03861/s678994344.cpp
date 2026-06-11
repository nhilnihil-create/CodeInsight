#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;

ll a,b,x;
ll CountOfMultiples(ll n) {
	if (n == -1) return 0;
	else return n/x + 1;
}

int main() {
	cin >> a >> b >> x;
	ll ans = CountOfMultiples(b) - CountOfMultiples(a-1);
	cout << ans << endl;	
	return 0;
}