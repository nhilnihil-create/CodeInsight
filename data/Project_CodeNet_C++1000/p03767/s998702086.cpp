#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	ll N; cin >> N;
	vector<ll> a(3*N);
	for (int i = 0; i < 3*N; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans += a[3*N - 2 - 2 * i];
	}
	cout << ans << endl;
}
