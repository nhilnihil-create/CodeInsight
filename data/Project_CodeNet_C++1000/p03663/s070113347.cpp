#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

ll N = 999999999;
string query(ll A) {
	cout << "? " << A << endl;
	string ret;

	//ここにお試し処理
	//string SN = to_string(N);
	//string SA = to_string(A);
	//if (A <= N && SA <= SN) ret = "Y";
	//else if (A > N && SA > SN) ret = "Y";
	//else ret = "N";
	//ce(ret);

	//ここに本番処理
	cin >> ret;

	return ret;
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	//いらないか
	//cin >> N;

	bool A[10] = {};
	ll k = 1;
	ll y = 0;
	rep(i, 10) {
		A[i] = (query(k) == "Y");
		if (A[i]) y = k;
		k *= 10;
	}

	if (y == 1000000000) {
		k = 2;
		rep(i, 10) {
			if (query(k) == "Y") break;
			k *= 10;
		}
		cout << "! " << k / 2 << endl;
	}
	else {
		ll L = y * 10;
		ll R = y * 100;
		while (L + 1 < R) {
			ll M = (L + R) / 2;
			if (query(M) == "Y") R = M;
			else L = M;
		}
		cout << "! " << R / 10 << endl;
	}

	Would you please return 0;
}