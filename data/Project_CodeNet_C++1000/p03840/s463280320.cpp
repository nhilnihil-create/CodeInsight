#include<bits/stdc++.h>
#include <array>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
using LL = long long;
using ULL = unsigned long long;


void solve() {
	unsigned I, O, T, J, L, S, Z; cin >> I >> O >> T >> J >> L >> S >> Z;
	ULL ans = 0;
	ans += O;
	if(I>0 && J>0 && L>0)
		if (I % 2 + J % 2 + L % 2 >= 2) {
			ans += 3;
			I--; J--; L--;
		}
	ans += (I / 2 * 2 + J / 2 * 2 + L / 2 * 2);
	cout << ans << endl;
}


int main() {

	solve();

	return 0;
}
