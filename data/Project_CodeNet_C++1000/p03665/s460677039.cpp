#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ll comb(ll n, ll r){
    ll num = 1;
    for(ll i = 1; i <= r; i++){
        num = num * (n - i + 1) / i;
    }
    return num;
}

ll pow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

int main() {
	ll N, P;
	cin >> N >> P;

	ll evenNum = 0;
	ll oddNum = 0;
	for (int ii = 0; ii < N; ++ii){
		ll A;
		cin >> A;
		if (A % 2 == 0){
			evenNum++;
		} else {
			oddNum++;
		}
	}

	ll ans = pow(2, evenNum);
	ll sum = 0;
	if (P == 0){
		for (int ii = 0; ii <= oddNum; ++ii){
			if (ii % 2 == 0){
				sum += comb(oddNum, ii);
			}
		}
	} else {
		for (int ii = 0; ii <= oddNum; ++ii){
			if (ii % 2 == 1){
				sum += comb(oddNum, ii);
			}
		}
	}

	cout << ans * sum << endl;


	return 0;
}
