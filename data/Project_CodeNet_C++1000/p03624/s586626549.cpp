#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<functional>
#include <tuple>
#include <map>
#include<set>
#include <cmath>
#include <stack>
#include<cstdio>
#include<stdio.h>
using namespace std;

int main() {
	string s,ans="None";
	cin >> s;
	vector<bool> b(26, false);
	for (int i = 0;i < s.size();i++) {
		b[s[i] - 'a'] = true;
	}
	for (int i = 0;i < 26;i++) {
		if (b[i] == false) {
			ans = i + 'a';
			break;
		}
	}
	cout << ans << endl;
}