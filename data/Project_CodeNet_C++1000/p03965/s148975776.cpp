#include <bits/stdc++.h>
using namespace std;

int ans;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	
 	cin >> s;
 	for (int i = 0; i < s.size(); i++) {
 		if (!(i&1)) {
 			ans -= (s[i] == 'p');
 		}
 		else {
 			ans += (s[i] == 'g');
 		}
 	}
 	cout << ans << '\n';
 	
	return 0;
}