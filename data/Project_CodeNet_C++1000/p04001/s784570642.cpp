#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
#define TE 2e6+5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	string s; cin >> s;
	int len = s.size();
	int mx = pow(2, len-1);

	ll ans = 0;
	for (int i = 0; i < mx; i++) {
		int left = 0;
		string temp;
		for (int j = 0; j < len - 1; j++) {
			if (i & 1 << j) {
				temp = s.substr(left, j - left + 1);
				ll ad = 0, tl = temp.size();
				for (int k = 0; k < tl; k++) {
					ad *= 10;
					ad += temp[k] - '0';
				}
				ans += ad;
				left = j + 1;
			}
			
		}

		temp = s.substr(left, (len - 1) - left + 1);
		ll ad = 0, tl = temp.size();
		for (int k = 0; k < tl; k++) {
			ad *= 10;
			ad += temp[k] - '0';
		}
		ans += ad;

		//cout << "ans=" << ans << endl;
	}
	cout << ans << endl;
}
