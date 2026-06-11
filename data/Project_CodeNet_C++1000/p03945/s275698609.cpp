#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	string s;
	cin >> s;
	ll ans = 0;
	for (int i = 0; i < s.size() - 1; i++) {
		if ((s[i] == 'B' && s[i + 1] == 'W') || (s[i] == 'W' && s[i + 1] == 'B')) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
