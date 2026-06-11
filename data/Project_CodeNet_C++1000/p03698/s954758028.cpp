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
	string s,ans="yes";
	set<string> a;
	cin >> s;
	for (int i = 1;i < s.size();i++) {
		for (int j = 0;j < i;j++) {
			if (s[i] == s[j]) {
				ans = "no";
				break;
			}
		}
	}
	cout << ans << endl;
}