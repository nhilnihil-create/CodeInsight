#include "bits/stdc++.h"
using namespace std;

int main() {
	string O,E;
	cin >> O >> E;
	string ans;
	for (int i = 0;i<E.size();++i) {
		ans += O[i];
		ans += E[i];
	}
	if (O.size() !=E.size()) {
		ans += O[O.size() - 1];
	}
	cout << ans << endl;
	return 0;
}