#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string s;
	cin >> s;
	vector<char> show;
	rep(i,s.size()) {
		if (s[i] == '0' || s[i] == '1') show.push_back(s[i]);
		else {
			if (show.size() == 0) continue;
			show.pop_back();
		}
	}
	for(char c : show) cout << c;
	cout << endl;

	return 0;
}
