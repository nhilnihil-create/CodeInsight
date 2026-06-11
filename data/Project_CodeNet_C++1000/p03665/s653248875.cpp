
// A - Biscuits

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

const int N_MAX = 50;

ll comb[N_MAX + 1][N_MAX + 1];

void init_comb() {
	comb[0][0] = 1;
	for (int i=1; i<=N_MAX; i++) {
		for (int j=0; j<=i; j++) {
			comb[i][j] += comb[i-1][j];
			if (j > 0) comb[i][j] += comb[i-1][j-1];
		}
	}
}

int main() {
	int N, P;
	cin >> N >> P;

	int E = 0, O = 0;
	for (int i=0; i<N; i++) {
		int A;
		cin >> A;
		if (A % 2 == 0) E++;
		else O++;
	}

	//cout << "E=" << E << " O=" << O << endl; // **** debug ****

	init_comb();

	ll even_comb = 0;
	for (int i=0; i<=E; i++) {
		even_comb += comb[E][i];
	}
	//cout << "choose from even " << even_comb << endl; // **** debug ****

	ll odd_comb = 0;
	for (int i=0; i<=O; i++) {
		odd_comb += comb[O][i];
	}
	//cout << "choose from odd " << odd_comb << endl; // **** debug ****


	ll odd_cases = 0;
	for (int i=1; i<=O; i+=2) {
		odd_cases += comb[O][i];
	}
	//cout << "odd cases in choose from odd " << odd_cases << endl; // **** debug ****


	ll ans;
	if (P == 1) {
		ans = odd_cases * even_comb;
	} else {
		ans = (odd_comb - odd_cases) * even_comb;
	}

	cout << ans << endl;

	return 0;
}