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
#define TE 2e6+5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N; cin >> N;
	vector<ll> a(N);
	map<ll, int> mp;
	for (int i = 0; i < N; i++) {
		cin >> a[i]; mp[a[i]] = i;
	}

	sort(a.begin(), a.end());
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (mp[a[i]] % 2 != i % 2)cnt++;
	}
	cout << cnt / 2 << endl;
}

