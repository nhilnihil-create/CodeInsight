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


	int N, L, T;
	cin >> N >> L >> T;
	int X[100000], W[100000];
	vector<int> A[3];
	rep(i, N) {
		cin >> X[i] >> W[i];
		W[i]--;
		if (W[i] == 0) A[0].pb(X[i]);
		else A[1].pb(X[i]);
	}

	int k = W[0];
	int aite = A[k ^ 1].size();

	int kaisuu = 0;
	kaisuu += (T / L) * 2 * aite;
	T = T % L;
	rep(i, aite) {
		int tmp = A[k ^ 1][i];
		if (k == 0) {
			if (X[0] >= tmp) tmp += L;
			while (X[0] + T > tmp - T) {
				kaisuu++;
				tmp += L;
			}
		}
		else {
			if (X[0] <= tmp) tmp -= L;
			while (X[0] - T <= tmp + T) {
				kaisuu++;
				tmp -= L;
			}
		}
	}
	kaisuu %= N;
	
	vector<int> V;
	rep(i, N) {
		if (W[i] == 0) V.pb((X[i] + T) % L);
		else V.pb((X[i] - (T % L) + L) % L);
	}

	sort(V.begin(), V.end());

	if (k == 0) {
		int doko = (X[0] + T) % L;
		int itr = lower_bound(V.begin(), V.end(), doko) - V.begin();

		int kotae[100100];
		int kari = 0;
		for (int i : V) {
			kotae[(kari + N + kaisuu - itr) % N] = i;
			kari++;
		}
		rep(i, N) co(kotae[i]);
	}
	else {
		int doko = (X[0] - (T % L) + L) % L;
		int itr = lower_bound(V.begin(), V.end(), doko) - V.begin();

		int kotae[100100];
		int kari = 0;
		for (int i : V) {
			kotae[(kari + N + N - kaisuu - itr) % N] = i;
			kari++;
		}
		rep(i, N) co(kotae[i]);
	}

	Would you please return 0;
}