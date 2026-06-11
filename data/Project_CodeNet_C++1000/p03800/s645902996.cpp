#include <bits/stdc++.h>
using namespace std;


int chk(string s, string str, int n) {
	for(int i = 0; i < n; i++) {
		char prv = str[(i + n - 1) % n], nxt = str[(i + 1) % n];
		if(str[i] == 'S') {
			if((prv != nxt) && s[i] == 'o') {
				return 0;
			}
			if((prv == nxt) && s[i] == 'x') {
				return 0;
			}
		} else {
			if((prv == nxt) && s[i] == 'o') {
				return 0;
			}
			if((prv != nxt) && s[i] == 'x') {
				return 0;
			}
		}
	}
	return 1;
}

string construct(string str, string s, int n) {
	for(int i = 1; i < n - 1; i++) {
		char ch = s[i - 1];
		if(s[i] == 'S') {
			if(str[i] == 'o') {
				s.push_back(ch);
			} else {
				s.push_back(ch ^ 'S' ^ 'W');
			}
		} else {
			if(str[i] == 'x') {
				s.push_back(ch);
			} else {
				s.push_back(ch ^ 'S' ^ 'W');
			}
		}
	}
	return s;
}

int main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; string s; cin >> n >> s;
	string ss[] = {"SS", "WW", "SW", "WS"};
	for(int i = 0; i < 4; i++) {
		string k = construct(s, ss[i], n);
		if(chk(s, k, n)) {
			cout << k << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}