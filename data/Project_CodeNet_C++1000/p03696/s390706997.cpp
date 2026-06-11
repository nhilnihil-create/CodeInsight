#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
int main()
{
	int n, left, right;
	string s;
	cin >> n;
	cin >> s;
	left = right = 0;
	rep(i, n) {
		if (s[i] == '(')	left++;
		else {
			if (0 < left)	left--;
			else right++;
		}
	}
	string ans = "";
	rep(i, right)	ans += '(';
	ans += s;
	rep(i, left)	ans += ')';
	cout << ans << endl;
	return 0;
}