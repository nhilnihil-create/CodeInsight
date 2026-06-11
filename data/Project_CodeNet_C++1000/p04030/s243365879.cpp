#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	vector<char> sta;
	for(int i=0; i<s.size(); i++) {
		if(s[i] == 'B') {
			if(!sta.empty()) {
				sta.pop_back();
			}
		}
		else {
			sta.push_back(s[i]);
		}
	}
	for(auto j : sta) {
		cout << j;
	}
	cout << endl;
	return 0;
}
