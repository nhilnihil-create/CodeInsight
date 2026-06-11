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
	int N; cin >> N;
	vector<ll> T(N), A(N);
	for (int i = 0; i < N; i++) {
		cin >> T[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	vector<pair<ll, bool>> t(N), a(N);
	for (int i = 0; i < N; i++) {
		t[i].first = T[i];
		t[i].second = (i == 0 || T[i - 1] != T[i]);
	}

	for (int i = N - 1; i >= 0; i--) {
		a[i].first = A[i];
		a[i].second = (i == N - 1 || A[i] != A[i + 1]);
	}

	ll ans = 1;
	for (int i = 0; i < N && ans>0; i++) {
		if (t[i].second && a[i].second) {
			if (t[i].first != a[i].first)ans = 0;
		}
		else if (t[i].second) {
			if (t[i].first > a[i].first) {
				ans = 0;
			}
		}
		else if (a[i].second) {
			if (t[i].first < a[i].first) {
				ans = 0;
			}
		}
		else ans *= min(t[i].first, a[i].first);
		ans %= DIV;
	}

	cout << ans << endl;

}