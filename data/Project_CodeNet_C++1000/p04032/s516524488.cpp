#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;


int main() {
	string s;
	cin >> s;
	for (int i = 2; i < s.size(); i++) {
		if (s[i] == s[i - 1]) {
			cout << i << ' ' << i+1;
			return 0;
		}
		if (s[i] == s[i - 2]) {
			cout << i - 1 << ' ' << i+1;
			return 0;
		}
	}
	if (s[0] == s[1]) {
		cout << "1 2";
		return 0;
	}
	cout << "-1 -1";
}