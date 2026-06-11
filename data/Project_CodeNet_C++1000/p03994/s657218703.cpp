#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main(){
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == 'a') {
			continue;
		}
		if (int('z' - s[i] + 1) <= k) {
			k -= int('z' - s[i] + 1);
			s[i] = 'a';
		}
	}
	if (int(s[n - 1] + k) > int('z')) {
		while (int(s[n - 1] + k) > int('z')) {
			k -= 26;
		}
		s[n - 1] = char(s[n - 1] + k);
	}
	else {
		s[n - 1] = char(s[n - 1] + k);
	}
	cout << s << endl;
	return 0;
}