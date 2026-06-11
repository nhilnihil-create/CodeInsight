#include <bits/stdc++.h>
using namespace std;
 
string s;
bool check[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	int i = 0;
	while (i < s.length() && !check[s[i] - 'a']) {
		check[s[i] - 'a'] = 1;
		i++;
	}
	if (i == s.length()) cout << "yes";
	else cout << "no";
}