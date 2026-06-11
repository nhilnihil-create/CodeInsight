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
const int INF = 1000000001;
const long long LINF = 1e18;
const int MAX = 510000;

int main() {
	string s;
	cin >> s;
	vector<bool> f(4);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'N') { f.at(0) = 1; }
		if (s[i] == 'S') { f.at(1) = 1; }
		if (s[i] == 'W') { f.at(2) = 1; }
		if (s[i] == 'E') { f.at(3) = 1; }
	}
	if (f.at(0) == f.at(1) && f.at(2) == f.at(3))cout << "Yes" << endl;
	else {
		cout << "No" << endl;
	}



		return 0;
}