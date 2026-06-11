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


	int N;
	cin >> N;
	int A[100000];
	rep(i, N) cin >> A[i];

	int k = 0;
	vector<int> V, V2;
	V.pb(0);
	rep(i, N) {
		if (A[i] > k) {
			V.pb(A[i]);
			V2.pb(i);
			k = A[i];
		}
	}
	ll B[100001] = {};
	int C[100001] = {};
	rep(i, N) {
		int k2 = lower_bound(V.begin(), V.end(), A[i]) - V.begin();
		B[k2] += A[i] - V[k2 - 1];
		C[k2]++;
	}

	int mae = V.back();
	ll l = C[(int)V.size()];
	ll kotae[100001] = {};
	for (int k = (int)V.size() - 2; k >= 0; k--) {
		kotae[V2[k]] = B[k + 1] + l * (mae - V[k]);
		mae = V[k];
		l += C[k + 1];
	}

	rep(i, N) co(kotae[i]);

	Would you please return 0;
}