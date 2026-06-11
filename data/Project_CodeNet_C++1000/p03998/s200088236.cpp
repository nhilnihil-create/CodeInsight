#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<string> s(3);
	cin >> s[0] >> s[1] >> s[2];
	unordered_map<char, int> mp;
	mp['a'] = 0;
	mp['b'] = 1;
	mp['c'] = 2;
	int nxt = 0;
	int ind = 0;
	while (1) {
		nxt = mp[s[ind][0]];
		s[ind].erase(s[ind].begin());
		ind = nxt;
		if (s[ind].size() == 0) {
			break;
		}
		//cout << s[0] << endl << s[1] << endl << s[2] << endl;
	}
	if (ind == 0) cout << "A";
	else if (ind == 1) cout << "B";
	else cout << "C";
	return 0;

}
