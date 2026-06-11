#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	string s; cin >> s;
	int n = s.size(), k; cin >> k;
	for(auto &i : s) i -= 'a';

	for(int i = 0; i < n - 1; i++) {
		//cerr << k <<" :" << endl;
		if(s[i] == 0)continue;
		if(26 - (int)s[i] <= k) {
			k -= (26 - (int)s[i]);
			s[i] = 0;
		}
		//cerr << k << endl;
	}

	s[n - 1] = (s[n - 1] + (k % 26)) % 26;
	for(auto i : s)cout << (char)(i + 'a');
	cout << endl;

}