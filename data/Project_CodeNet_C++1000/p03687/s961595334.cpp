#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	string s; cin >> s;
	for(auto &i : s) i -= 'a';

	int ans = 1e9;

	for(int i = 0; i < 26; i++) {
		if(count(s.begin(), s.end(), i) == 0) continue;
		string t = s;
		int cnt = 0;

		while((int)t.size() != count(t.begin(), t.end(), i) && t.size()) {
			string td = t;
			int nn = t.size();
			td.pop_back();
			for(int j = 0; j < nn - 1; j++) {
				if(t[j] == i || t[j + 1] == i) {
					td[j] = i;
				}
			}
			t = td;
			cnt++;

		}
		ans = min(cnt ,ans);
	}
	cout << ans << endl;

}