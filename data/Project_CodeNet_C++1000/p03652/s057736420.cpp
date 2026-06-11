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


	int N, M;
	cin >> N >> M;
	int A[300][300];
	int R[300][300];
	rep(i, N) rep(j, M) {
		cin >> A[i][j];
		A[i][j]--;
		R[i][A[i][j]] = j;
	}

	bool C[300][310] = {};
	int doko[300] = {};
	int kotae = 1e9;
	rep(j, M) {
		int B[300] = {};
		rep(i, N) B[A[i][doko[i]]]++;
		auto saidaip = max_element(B, B + M);
		kotae = min(kotae, *saidaip);
		int kesu = saidaip - B;
		rep(i, N) {
			C[i][R[i][kesu]] = true;
			while (C[i][doko[i]]) doko[i]++;
		}
	}

	co(kotae);

	Would you please return 0;
}