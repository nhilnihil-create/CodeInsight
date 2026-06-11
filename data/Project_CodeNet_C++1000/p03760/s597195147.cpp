#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
	string o, e;
	cin >> o >> e;

	int i = 0;
	while (o[i] != NULL) {
		cout << o[i];
		if (e[i] != NULL) cout << e[i];
		i++;
	}
	return 0;
}