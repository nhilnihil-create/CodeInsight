#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	string S, T; cin >> S >> T;
	vector<int> X(S.size()+1);
	vector<int> Y(T.size()+1);
	for (int i = 0; i < int(S.size()); i++) X[i+1] = (X[i] + (S[i] - 'A' + 1)) % 3;
	for (int i = 0; i < int(T.size()); i++) Y[i+1] = (Y[i] + (T[i] - 'A' + 1)) % 3;

	int Q; cin >> Q;
	while (Q--) {
		int a, b, c, d; cin >> a >> b >> c >> d; a--, c--;
		cout << ((X[b] - X[a] - Y[d] + Y[c]) % 3 == 0 ? "YES" : "NO") << '\n';
	}

	return 0;
}
