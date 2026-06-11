#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
	ll K, S; cin >> K >> S;
	ll ans = 0;
	for (int i = 0; i <= K; ++i) {
		for (int j = 0; j <= K; ++j) {
			ll z = S - i - j;
			if (z >= 0 && z <= K) ans++;
		}
	}
	cout << ans << endl;



}
