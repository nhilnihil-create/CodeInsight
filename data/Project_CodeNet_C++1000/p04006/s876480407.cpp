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
	int A[2000];
	rep(i, N) cin >> A[i];

	ll kotae = 1e18;
	rep(i, N) {
		ll kei = 0;
		rep(j, N) kei += A[j];
		kotae = min(kotae, kei + X * i);

		int saisho = A[0];
		rep(j, N - 1) {
			A[j] = min(A[j], A[j + 1]);
		}
		A[N - 1] = min(A[N - 1], saisho);
	}

	co(kotae);

	Would you please return 0;
}