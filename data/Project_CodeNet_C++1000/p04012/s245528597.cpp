#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<int> freq(26, 0);
	string s;
	cin >> s;
	int n = int(s.size());
	for(int i = 0; i < n; ++i){
		++freq[s[i] - 'a'];
	}
	bool ok = true;
	for(int i = 0; i < 26; ++i){
		ok &= (freq[i] % 2 == 0);
	}
	cout << (ok ? "Yes" : "No" ) << '\n';
	return 0;
}