#include <bits/stdc++.h>

#define fr first
#define sc second
#define mk make_pair
#define pb push_back

using namespace std;

typedef long long ll;

const int N = 1e6 + 5;

int main() {
	string s;
	int ans = 0, g = 0, p = 0, w = 0, l = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] == 'g') {
			if (p < g) p ++, w ++;
			else g ++;
		}
		else if (s[i] == 'p') {
			if (p < g) p ++;
			else g ++, l ++;
		}
	}
	ans = w - l;
	cout << ans << endl;
	return 0;
}