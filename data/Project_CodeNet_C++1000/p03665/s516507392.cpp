#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;

ll comb(int n, int r) {
	ll res=1;
	for (int i = 1; i <= r; i++) {
		res = res * (n - i + 1) / i;
	}
	return res;
}

ll pow2(int n) {
	if (n == 1)return 2;
	if (n == 0)return 1;

	auto temp = pow2(n / 2);
	if (n % 2 == 0) return temp * temp;
	else return temp * temp * 2;
}

ll solver(int N, int P, const vector<int> & A) {
	int even = 0, odd = 0;
	for (auto x : A) {
		if (x % 2 == 0)even++;
		else odd++;
	}
	ll even2 = pow2(even);

	ll ans = 0;
	for (int i = P; i <= N; i += 2) {
		ans += comb(odd, i)*even2;
	}

	return ans;
}

int main(void) {
	int N; cin >> N;
	int P; cin >> P;
	vector<int> A(N);
	rep(i, N)cin >> A[i];


	cout << solver(N, P, A) << endl;

	return 0;
}