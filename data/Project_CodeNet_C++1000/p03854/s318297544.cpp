#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	string s; cin >> s;
	string d = "dream";
	string e = "erase";
	string er = "eraser";
	string der = "dreamer";	

	reverse(s.begin(), s.end());
	reverse(d.begin(), d.end());
	reverse(e.begin(), e.end());
	reverse(er.begin(), er.end());
	reverse(der.begin(), der.end());

	int n = s.size();
	int index = 0;
	bool can = true;
	while (s != "") {
		
		string  tmp_s_5;
		string  tmp_s_6;
		string  tmp_s_7;

		if (d.size() <= s.size()) {
			tmp_s_5 = s.substr(index, d.size());
		}
		if (er.size() <= s.size()) {
			tmp_s_6 = s.substr(index, er.size());
		}
		if (der.size() <= s.size()) {
			tmp_s_7 = s.substr(index, der.size());
		}

		if (tmp_s_5 == d || tmp_s_5 == e) {
			s = s.substr(index + d.size());
		}
		else if (tmp_s_6 == er) {
			s = s.substr(index + er.size());
		}
		else if (tmp_s_7 == der) {
			s = s.substr(index + der.size());
		}
		else {
			can = false;
			break;
		}
	}

	if (can) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}