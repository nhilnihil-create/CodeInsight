#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())
typedef long long ll;

ll k;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin >> k;
	ll a = k / 50, b = k % 50;
	cout << 50 << endl;
	if (b == 0) {
		FOR(i, 50) {
			if (i < 49) cout << 49 + a << " ";
			else cout << 49 + a << endl;
		}
	}
	else {
		ll c = (49 + a) + (51 - b), d = (49 + a) - b;
		FOR(i, 50) {
			if (i < b) cout << c;
			else cout << d;
			if (i < 49) cout << " ";
			else cout << endl; 
		}
	}

	return 0;
}