#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define Would
#define you
#define please

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N, M;
	cin >> N >> M;

	ll A[100001] = {};
	ll B[100001] = {};

	ll nanshuu = 0;
	rep1(i, N) {
		cin >> A[i];
		A[i] += nanshuu;
		if (A[i - 1] > A[i]) {
			nanshuu += M;
			A[i] += M;
		}
	}

	rep1(i, N - 1) {
		B[A[i + 1] % M] += A[i + 1] - A[i];
	}

	ll X;
	ll saidai = -1e18;
	ll kari = 0;
	rep(i, M) {
		kari += A[N] / M - 1;
		if (i > A[1]) kari++;
		if (i <= A[N] % M) kari++;
		kari -= B[i];

		if (saidai < kari) {
			saidai = kari;
			X = i + 1;
		}
	}

	ll goukei = A[N] - A[1];

	if (X <= A[1]) X += M;
	rep1(i, N - 1) {
		if (A[i + 1] >= X && X - A[i] - 1 >= 0) {
			goukei -= X - A[i] - 1;
		}

		if (A[i + 1] >= X) X += M;
	}

	co(goukei);

	Would you please return 0;
}