#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000000;
const long long LINF = 1e18;
const int MAX = 510000;
int main() {
	int j = 0;
	bool f = 1;
	string s;
	vector<int> cnt(26);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		cnt.at((char)s[i] - 'a')++;
	}
	for (int i = 0; i < 26; i++) {
		if (cnt.at(i) % 2 == 1)f = 0;
	}
	if (f == 1)cout << "Yes" << endl;
	else {
		cout << "No" << endl;

	}
	return 0;

}