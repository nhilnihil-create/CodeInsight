#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	ll A, B, C;
	cin >> A >> B >> C;
	ll c = 0;
	if (A==B && B==C && A%2 == 0) {
		cout << -1 << endl;
		return 0;
	}
	while (A%2 == 0 && B%2 == 0 && C%2 == 0){
		ll Ah = A/2;
		ll Bh = B/2;
		ll Ch = C/2;
		A = Bh + Ch;
		B = Ch + Ah;
		C = Ah + Bh;
		c++;
	}

	cout << c << endl;

	return 0;
}
