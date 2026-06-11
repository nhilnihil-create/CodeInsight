#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#define int long long
#define mod(int)(1000000007)
using namespace std;
signed main() {
	int n, m, a = 0; string s; cin >> s >> n;
	for (int h = 0; h < s.size(); h++) {
		if (h == s.size() - 1) {
			n %= 26;
			if ((int)s[h] + n >= 123) { n -= 26; }
			s[h] = (char)((int)s[h] + n);
		}
		else if (123 - (int)s[h] <= n && s[h] != 'a') { n -= 123 - (int)s[h]; s[h] = 'a'; }
	}
	cout << s << endl;
	return 0;
}