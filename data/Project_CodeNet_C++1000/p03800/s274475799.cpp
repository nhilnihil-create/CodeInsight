#include <sys/time.h>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <cctype>

using namespace std;

using ll = long long;
using P = pair<double, double>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
ll mod = 1000000007LL;

//  S o: 左右がW W or S S; x;　W　S　or 　S　W 
//  S o: 

string solve(string& s, char c0, char c1) {
	int n = s.size();
	string ans(n,' ');
	ans[0] = c0;
	ans[1] = c1;
	for(int i = 2; i < n; i++) {

		bool is_same = (s[i - 1] == 'o');
		//cout << "i:" << i << " is_same:" << is_same << endl;

		if (ans[i - 1] == 'W') {
			is_same = !is_same;
		}
		//cout << "i:" << i << " is_same:" << is_same << endl;


		if (is_same) {
			ans[i] = ans[i - 2];

		} else {
			ans[i] = ans[i - 2] == 'W' ? 'S' : 'W'; 
		}
	}

	// i == 0

	bool is_same0 = s[n - 1] == 'o';
	if (ans[n - 1] == 'W') {
		is_same0 = !is_same0;
	}
	if ((ans[0] == ans[n - 2]) != is_same0) {
		return "";
	}

	// i == 1
	bool is_same1 = s[0] == 'o';
	if (ans[0] == 'W') {
		is_same1 = !is_same1;
	}
	if ((ans[1] == ans[n - 1]) != is_same1) {
		return "";
	}

	return ans;
}

int main() {
	int n;
	string s;
	cin >> n >> s;


	string ans = solve(s, 'S', 'S' );
	if (ans != "") {
		cout << ans << endl;
		return 0;
	}
	ans = solve(s, 'W', 'W' );
	if (ans != "") {
		cout << ans << endl;
		return 0;
	}
	ans = solve(s, 'W', 'S' );
	if (ans != "") {
		cout << ans << endl;
		return 0;
	}
	ans = solve(s, 'S', 'W' );
	if (ans != "") {
		cout << ans << endl;
		return 0;
	}

	cout << -1 << endl;



	return 0;
}
