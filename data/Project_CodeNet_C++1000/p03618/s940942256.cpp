#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	string s; cin >> s;
	ll n = s.size();
	vector<ll> alp(26);
	for (int i = 0; i < n; i++) {
		alp[s[i] - 'a']++;
	}

	ll ans = n * (n - 1) / 2 + 1;
	for (int i = 0; i < 26; i++) {
		ans -= alp[i] * (alp[i] - 1) / 2;
	}
	cout << ans << endl;
}
