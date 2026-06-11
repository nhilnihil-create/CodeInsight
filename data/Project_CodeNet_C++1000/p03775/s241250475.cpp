#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repbit(bit,n) for (int bit = 0; bit < (1<<n); bit++)
using namespace std;
typedef long long ll;

const int INF = 1001001001;
//const ll INF = 1000000000000000000;

ll a, b, v, w, t;

int main() {
	ll n;
	cin >> n;

	ll tmp = INF;
	for (int a = 1; a <= sqrt(n); a++) {
		if (n % a != 0) continue;
		ll b = n/a;
		tmp = min(b, tmp);
	}
	int ans = 0;
	string s;
	s = to_string(tmp);
	ans = s.size();
	cout << ans << endl;
	return 0;
}
