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
	string s, t;
	cin >> s >> t;
	if (s.size() > t.size())cout << "GREATER" << endl;
	else if (s.size() < t.size())cout << "LESS" << endl;
	else {
		for (int i = 0; i < s.size(); i++) {
			if (s[i]-'0' > t[i]-'0') {
				cout << "GREATER" << endl;
				return 0;
			}
			else if (s[i] -'0'< t[i]-'0') {
				cout << "LESS" << endl;
				return 0;
			}
	
		}

		cout << "EQUAL" << endl;
	}
	return 0;
}