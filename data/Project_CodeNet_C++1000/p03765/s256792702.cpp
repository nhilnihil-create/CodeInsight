#include "bits/stdc++.h"
using namespace std;

int main() {
	string S, T;
	static int SS[100010] = {}, TS[100010] = {}, Q, A, B, C, D;
	cin >> S >> T >> Q;
	for (int i = 0; i < S.size(); i++) SS[i + 1] = SS[i] + (S[i] == 'B') + 1;
	for (int i = 0; i < T.size(); i++) TS[i + 1] = TS[i] + (T[i] == 'B') + 1;
	for (int i = 0; i < Q; i++) {
		cin >> A >> B >> C >> D;
		if ((SS[B] - SS[A - 1]) % 3 == (TS[D] - TS[C - 1]) % 3) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}