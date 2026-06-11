#include<iostream>
using namespace std;

int main() {
	string s; cin >> s;
	
	int n = s.size(), l = 0, r = 0; bool ok = false;
	for(int i = 0; i < n;i++) {
		if (s[i] == s[i + 1]) {
			l = i + 1;
			r = i + 2;
			ok = true;
			break;
		}

		if (i < n - 2 && s[i] == s[i + 2]) {
			l = i + 1;
			r = i + 3;
			ok = true;
			break;
		}
	}
	if (ok) cout << l << " " << r << endl;
	else cout << -1 << " " << -1 << endl;

	return 0;
}