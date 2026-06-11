#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
	string s;
	int k;
	cin >> s >> k;
	rep(i,s.size()) {
		if (s[i] == 'z') {
			if (k > 0) {
				s[i] = 'a';
				k--;
			}
		} 
		else if (s[i] == 'a') continue; 
		
		else {
			for (int j = 0; j <= min(25,k-1); j++) {
				if (char(s[i] + j) == 'z') {
					s[i] = 'a';
					k -= (j+1);
					break;
				}
			}
		}
	}
	int l = s.size();
	k = k % 26;
	rep(i,k) {
		if (s[l-1] == 'z') s[l-1] = 'a';
		else s[l-1] = char(s[l-1]+1);
	}
	cout << s << endl;
	return 0;
}