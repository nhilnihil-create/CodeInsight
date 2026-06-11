#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;

//typedef modint998244353 mint;

const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

const ll MAX = 1e9 + 5;

int main() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		int num = ('z' - s[i] + 1) % 26;
		if (num <= k) {
			s[i] = 'a';
			k -= num;
		}
	}

	if (k == 0) {
		cout << s << endl;
		return 0;

	}
	//cout << (s[n - 1] - 'a') + k << endl;
	s[n - 1] = 'a' + ((s[n-1]-'a') +k) % 26;
	cout << s << endl;
}