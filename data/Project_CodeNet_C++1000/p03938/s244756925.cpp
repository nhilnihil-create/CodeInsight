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
#define M 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	ll N; cin >> N;
	map<int, ll> mp;
	for (int i = 1; i <= N; i++) {
		int p; cin >> p;
		mp[p] = i;
	}

	vector<ll> a(N + 1), b(N + 1);
	for (ll i = 1; i <= N; i++) {
		a[i] = (ll)40000 * i + mp[i];
		b[i] = (ll)40000 * (N - i + 1);
	}

	for (int i = 1; i <= N; i++)cout << a[i] << " ";
	cout << endl;
	for (int i = 1; i <= N; i++)cout << b[i] << " ";
	cout << endl;
	//cout << 24000 * 20000 << endl;
}