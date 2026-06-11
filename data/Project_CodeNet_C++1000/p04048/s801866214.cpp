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
#define Would
#define you
#define please

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	ll N, X;
	cin >> N >> X;

	ll A = X;
	ll B = N - X;

	if (A == B) co(A * 3);
	else if (A < B) {
		ce(B);
		ll kotae = N;
		while (true) {
			kotae += (B / A) * 2 * A;
			ce(kotae);
			if (B % A == 0) {
				kotae -= A;
				co(kotae);
				return 0;
			}
			B = B % A;
			swap(A, B);
		}

	}
	else {

		ll kotae = A + B + (A / B) * 2 * B;
		if (A % B == 0) {
			kotae -= B;
			co(kotae);
			return 0;
		}
		A %= B;
		while (true) {
			kotae += (B / A) * 2 * A;
			if (B % A == 0) {
				kotae -= A;
				co(kotae);
				return 0;
			}
			B = B % A;
			swap(A, B);
		}
	}

	Would you please return 0;
}