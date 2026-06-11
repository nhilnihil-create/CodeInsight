#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <set>

using namespace std;
using ll = long long;

template<typename T> void print(T t) { cout << t << endl; }
ll MOD = 1000000007;


int calc(string s, char c,int n){
	int count = 0;
	bool perfect = true;
	if (n < 1)return 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] != c) {
			perfect = false;
			s[i] = s[i+1];
		}
	}
	if (perfect) {
		return s[n - 1] == c ? 0 : 1;
	}
	else {
		return 1 + calc(s, c, n - 1);
	}
}
int main() {
	string s;
	cin >> s;
	int ans = s.length();
	for (char c = 'a'; c <= 'z'; c++) {
		ans = min(ans, calc(s, c, s.length()));
		//cout << c << ":" << calc(s, c, s.length()) << endl;
	}
	print(ans);
}
