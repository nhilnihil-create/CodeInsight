#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	string s; cin >> s;
	int K; cin >> K;
	int L = s.size();
	for (int i = 0; i < L && K >= 0; i++) {
		if (s[i] != 'a') {
			if (26-(s[i]-'a') <= K) {
				K -= 26 - (s[i]-'a');
				s[i] = 'a';
			}
		}
	}
	if (K > 0) {
		s[L - 1] -= 'a';
		s[L - 1] = (s[L - 1] + K) % 26 + 'a';
	}
	cout << s << endl;
}
