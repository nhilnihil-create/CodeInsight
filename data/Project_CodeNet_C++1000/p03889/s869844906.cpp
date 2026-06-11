#include <bits/stdc++.h>
using namespace std;

int main(){
	cout.precision(13);
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	char m[256];
	for(char c = 'a'; c <= 'z'; ++c){
		m[c] = c;
	}
	m['b'] = 'd';
	m['d'] = 'b';
	m['p'] = 'q';
	m['q'] = 'p';
	string t = s;
	reverse(t.begin(), t.end());
	for(int i = 0;i < t.length(); ++i){
		t[i] = m[t[i]];
	}

	cout << (s == t?"Yes":"No") << '\n';
}
