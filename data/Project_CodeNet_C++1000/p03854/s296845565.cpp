#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	reverse(S.begin(),S.end());
	vector<string>vS = { "maerd","remaerd","esare","resare" };
	while (S.size()>0) {
		bool b = false;
		for (int i = 0;i<4;++i) {
			if (0 == S.find(vS[i])) {
				b = true;
				S = S.substr(vS[i].size());
			}
		}
		if (!b) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}

