#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <numeric>
typedef long long ll;
using namespace std;
const int MOD = (int)1e9 + 7;
const ll INF = (ll)1e18 + 7;
//#define int long long

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	
	if (s.size() < 4) {
		cout << "No" << endl;
		return 0;
	}

	bool flg = true;
	if (s[0] != 'Y')flg = false;
	if (s[1] != 'A')flg = false;
	if (s[2] != 'K')flg = false;
	if (s[3] != 'I')flg = false;

	if (flg) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
