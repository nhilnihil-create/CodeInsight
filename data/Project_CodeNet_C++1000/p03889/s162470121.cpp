#include<algorithm>
#include<iostream>
#include<string>
#include<map>
using namespace std;

string s, s_;
map<char, char> to;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s;
	s_ = s;
	reverse(s.begin(), s.end());
	to['b'] = 'd', to['d'] = 'b', to['p'] = 'q', to['q'] = 'p';
	for(auto &c : s) c = to[c];
	cout << (s == s_? "Yes": "No") << '\n';
	return 0;
}
