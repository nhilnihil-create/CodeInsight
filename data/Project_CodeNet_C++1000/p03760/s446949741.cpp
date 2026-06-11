#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string o, e; cin >> o >> e;
	string ans = "";
	int o_index = 0;
	int e_index = 0;
	for (int i = 0; i < o.size() + e.size(); i++) {
		if (i % 2 == 0) {
			ans += o[o_index];
			o_index++;
		}
		else {
			ans += e[e_index];
			e_index++;
		}
	}
	cout << ans << endl;
	return 0;
}