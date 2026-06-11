#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)
typedef long long ll;

using namespace std;

int main(void) {
	string S; cin >> S;
	S.erase(S.length() - 1);

	while (S.substr(0, S.length() / 2) != S.substr(S.length() / 2, S.length() - 1)) {
		S.erase(S.length() - 1);
	}

	cout << S.length() << endl;

	return 0;
}