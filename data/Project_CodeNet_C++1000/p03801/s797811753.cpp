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
	vector<pair<int, int>> V;
	V.pb(mp(0, 0));
	rep(i, N) {
		if (A[i] > k) {
			V.pb(mp(A[i], i + 1));
			k = A[i];
		}
	}
	ll B[100001] = {};
	int C[100001] = {};
	rep(i, N) {
		int k2 = lower_bound(V.begin(), V.end(), mp(A[i], 0)) - V.begin();
		B[k2] += A[i] - V[k2 - 1].first;
		C[k2]++;
	}


	int mae = V.back().first;
	ll l = C[(int)V.size()];
	ll kotae[100001] = {};
	for (int k = (int)V.size() - 2; k >= 0; k--) {
		kotae[V[k + 1].second] = B[k + 1] + l * (mae - V[k].first);
		mae = V[k].first;
		l += C[k + 1];
	}

	rep1(i, N) co(kotae[i]);

	Would you please return 0;
}