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
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

const int MAX = 1e5+5;



int main() {
	int h, w;
	cin >> h >> w;

	map<char, int> m;
	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for (char c : s) {
			m[c]++;
		}
	}

	int cnt1 = 0;
	int cnt2 = 0;
	for (auto it = m.begin(); it != m.end(); it++ ) {

		int num = it->second;
		num%= 4;
		if (num % 2 == 1) {
			cnt1++;
			num--;
		}

		if (num == 2) {
			cnt2++;

		}

	}

	if (cnt1 > 1) {
		cout << "No" << endl;
		return 0;
	}



	if ((h * w) % 2 == 0 && cnt1 > 0) {
		cout << "No" << endl;
		return 0;
	}

	cnt2 -= (h / 2) * (w % 2) + (w / 2) * (h % 2);
	
	if (cnt2 > 0) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}



}