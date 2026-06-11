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
	vector<ll> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	//sort(a.begin(), a.end(),greater<ll>());
	sort(a.begin(), a.end());
	vector<ll> sums(N + 1);
	for (int i = 0; i < N; i++) {
		sums[i + 1] = a[i] + sums[i];
	}
	ll ans = 1;
	for (int i = N - 1; i >= 0; i--) {
		//cout << sums[i] << endl;
		if (2*sums[i] >= a[i]) 
			ans++;
		else break;
	}
	cout << ans << endl;
}
