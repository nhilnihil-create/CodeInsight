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
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	ll N, K; cin >> N >> K;
	map<ll, ll> mp;
	for (int i = 0; i < N; i++) {
		ll a, b; cin >> a >> b;
		mp[a] += b;
	}

	ll cnt = 0;
	for(auto x:mp) {
		cnt += x.second;
		if (cnt >= K) {
			cout << x.first << endl;
			break;
		}
	}
}
