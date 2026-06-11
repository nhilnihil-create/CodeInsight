#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;	
	string a = "dream";
	string b = "dreamer";
	string c = "erase";
	string d = "eraser";
	reverse(s.begin(), s.end());
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	reverse(c.begin(), c.end());
	reverse(d.begin(), d.end());
	int na = a.size(); // 5
	int nb = b.size(); // 7
	int nc = na;       // 5
	int nd = d.size(); // 6
	string tmp_s = s;
	bool can = true;
	while (true) {
	//while (na <= tmp_s.size()) {
	//while (tmp_s != "") {
		if (nb <= tmp_s.size()) {
			if (tmp_s.substr(0, na) == a || tmp_s.substr(0, nc) == c) {
				tmp_s = tmp_s.substr(na);
			}
			else if (tmp_s.substr(0, nb) == b) {
				tmp_s = tmp_s.substr(nb);
			}
			else if (tmp_s.substr(0, nd) == d) {
				tmp_s = tmp_s.substr(nd);
			}
			else {
				can = false;
				break;
			}
			if (tmp_s.size() == 0) break;
		}
		else if (tmp_s.size() == nd) {
			if (!(tmp_s == d)) {
				can = false;
			}
			break;
		}
		else if (tmp_s.size() == na) {
			if (!(tmp_s == a || tmp_s == c)) {
				can = false;
			}
			break;
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