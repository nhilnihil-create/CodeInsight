#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>

using namespace std;

typedef long long ll;

int main() {
	string s;
	cin >> s;
	int fn = 0, fe = 0, fw = 0, fs = 0;
	int len = s.size();
	for (int i = 0; i < len; ++i) {
		if (s[i] == 'N') {
			fn = 1;
		}
		if (s[i] == 'E') {
			fe = 1;
		}
		if (s[i] == 'W') {
			fw = 1;
		}
		if (s[i] == 'S') {
			fs = 1;
		}
	}
	if (fn == fs && fe == fw) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}