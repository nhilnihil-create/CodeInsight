#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	vector <int> cnt(26);
	for (int i = 0; i < s.length(); ++i) cnt[s[i]-'a']++;
	for (int i = 0; i < 26; ++i){
		if (cnt[i] == 0) {
			char c = 'a' + i;
			cout << c  << "\n";
			return 0;
		}
	}
	cout << "None" << "\n";	
	return 0;
}
