#define _GLIBCXX_DEBUG
#include "bits/stdc++.h"
//#include <intrin.h>  //AtCoder (gcc) 上ではこれがあると動かない。__popcnt用のincludeファイル。
using namespace std;
using Graph = vector<vector<int>>;

typedef long long ll;
typedef long double ld;


#define int long long
#define rep(i, n) for(long long i = 0; i < (n); i++)
#define sqrt(d) pow((long double) (d), 0.50)

const ll INF = 2e9;
const ll large_P = 1e9 + 7;



//繰り返し2乗法
//N^aの、Mで割った余りを求める。
//M = 1000000007 (1e9 + 7) など。
//M = 1000000009 (1e9 + 9) もある。
//M = 998244353 もある。

ll my_pow(ll N, ll a, ll M) {
	ll tempo;
	if (a == 0) {
		return 1;
	}
	else {
		if (a % 2 == 0) {
			tempo = my_pow(N, a / 2, M);
			return (tempo * tempo) % M;
		}
		else {
			tempo = my_pow(N, a - 1, M);
			return (tempo * N) % M;
		}
	}
}




signed main() {
	int N; cin >> N;
	vector<int> A(N);
	rep(i, N) cin >> A.at(i);

	bool able = true;
	vector<int> position(N);

	rep(i, N) {
		position.at(A.at(i))++;
	}

	if (N % 2 == 1) {
		if (!position.at(0) == 1) able = false;
		if (N != 1 && able) {
			for (int i = 1; i < N; i++) {
				if (i % 2 == 1 && position.at(i) != 0) {
					able = false;
					break;
				}
				if (i % 2 == 0 && position.at(i) != 2) {
					able = false;
					break;
				}
			}
		}
		
	}
	else {
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0 && position.at(i) != 0) {
				able = false;
				break;
			}
			if (i % 2 == 1 && position.at(i) != 2) {
				able = false;
				break;
			}
		}
	}

	if (!able) cout << 0 << endl;
	else {
		ll res = my_pow(2, N / 2, large_P);
		cout << res << endl;
	}

}