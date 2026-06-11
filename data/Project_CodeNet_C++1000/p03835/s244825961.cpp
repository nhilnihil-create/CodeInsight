#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;
const ll mod = 998244353;

int main(){
	int K, S;
	cin >> K >> S;
	ll ans = 0;

	if (S %3 == 0) ans++;

	rep(i,K+1) {
		int x = S - 2*i;
		if (x == i) continue;	
		if (x>=0 && x<=K) ans += 3;
	}
	
	for (int i = 0; i <= K; i++) {
		for (int j = i+1; j <= K; j++) {
			int x = S - i - j;
			if (x>j && x<=K) ans += 6;
		}
	}

	cout << ans << endl;
	return 0;
}

