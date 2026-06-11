#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>


using namespace std;

typedef long long ll;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
const int BIG_INT = 1000000000;



int main() {
	
	int n;
	cin >> n;
	vector<string> s(2);
	for (int i = 0; i < 2;i++) {
		cin >> s[i];
	}

	ll ans = 1;
	bool isLastV = false;
	bool isLastH = false;
	for (int i = 0; i < n; i++) {
		
		if (i < n-1 && s[0][i] == s[0][i + 1]) {
			if (isLastV) {
				ans = (ans * 2) % MOD_CONST;
			}
			else if (isLastH) {
				ans = (ans * 3) % MOD_CONST;
			}
			else {
				ans = (ans * 6) % MOD_CONST;
			}
			isLastH = true;
			isLastV = false;
			
		}

		if (s[0][i] == s[1][i]) {
			if (isLastV) {
				ans = (ans * 2) % MOD_CONST;
			}
			else if (isLastH) {
				ans = (ans * 1) % MOD_CONST;
			}
			else {
				ans = (ans * 3) % MOD_CONST;
			}
			isLastH = false;
			isLastV = true;

			
		}
		
	}

	cout << ans << endl;
}
