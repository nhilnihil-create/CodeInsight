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

#define DIV 998244353
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	ll N; cin >> N;
	vector<ll> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	ll ans = a[0] - 1, mx = 2;
	for (int i = 1; i < N; i++) {
		if (a[i] == mx)mx++;
		else ans += (a[i] - 1) / mx;
		//cout << "ans=" << ans << endl;
	}

	cout << ans << endl;
}