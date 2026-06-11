#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
int mod = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		ans = ((ans % mod)  * 1LL *  (i % mod)) % mod; 
	}
    cout << ans;
}

















