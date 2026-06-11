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

	//見やすくした
	int N;
	cin >> N;
	int A[300001];
	rep(i, 3 * N) cin >> A[i];

	ll S1[100001] = {}, S2[100001] = {};

	map<int, int> B, C;
	rep(i, N) {
		B[A[i]]++;
		C[A[2 * N + i]]++;
	}

	rep(i, N) S1[0] += A[i];

	rep1(i, N) {
		int K = B.begin()->first;
		if (K < A[N + i - 1]) {
			S1[i] = S1[i - 1] + A[N + i - 1] - K;
			B[K]--;
			if (B[K] == 0) B.erase(K);
			B[A[N + i - 1]]++;
		}
		else {
			S1[i] = S1[i - 1];
		}
	}

	rep(i, N) S2[0] += A[2 * N + i];
	reverse(A + N, A + 2 * N);

	rep1(i, N) {
		int K = (--C.end())->first;
		if (K > A[N + i - 1]) {
			S2[i] = S2[i - 1] + A[N + i - 1] - K;
			C[K]--;
			if (C[K] == 0) C.erase(K);
			C[A[N + i - 1]]++;
		}
		else {
			S2[i] = S2[i - 1];
		}
	}

	ll S[100001];
	rep(i, N + 1) {
		S[i] = S1[i] - S2[N - i];
	}

	co(*max_element(S, S + N + 1));

	Would you please return 0;
}