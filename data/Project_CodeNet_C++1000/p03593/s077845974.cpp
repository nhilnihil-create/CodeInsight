#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <list>
#include <unordered_set>
#include <tuple>
#include <cmath>
#include <limits>
#include <type_traits>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <regex>
#include <random>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;++i)
#define exout(x) printf("%.10f\n", x)
const double pi = acos(-1.0);
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX_N = 201010;

//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	if (x == 0 || y == 0)return 0;
	return (x / gcd(x, y) * y);
}

ll dx[4] = { 0,0,-1,1 };
ll dy[4] = { -1,1,0,0 };
char a[110][110];

//long longしか使わない
//素数は1より大きい
//lower_boundは指定したkey以上の要素の一番左のイテレータをかえす
//upper_boundは指定したkeyより大きい要素の一番左のイテレータをかえす
int main() {
	ll h, w;
	cin >> h >> w;
	vector<ll>kazu(3);
	map<char, ll>mp;
	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
			mp[a[i][j]]++;
		}
	}
	for (auto p : mp) {
		ll res = p.second;
		kazu[2] += p.second / 4;
		p.second -= p.second / 4 * 4;
		kazu[1] += p.second / 2;
		p.second -= p.second / 2 * 2;
		kazu[0] += p.second;
	}
	ll res = (h / 2) * (w / 2);
	if (h % 2 == 0 && w % 2 == 0) {
		if (kazu[2] == res) {
			puts("Yes");
		}
		else {
			puts("No");
		}
	}
	else if (h % 2 && w % 2) {
		bool flag = true;
		if (kazu[0] != 1)flag = false;
		if (kazu[2] < res)flag = false;
		if (flag) {
			puts("Yes");
		}
		else {
			puts("No");
		}
	}
	else {
		bool flag = true;
		if (kazu[2] < res)flag = false;
		if (kazu[0] > 0)flag = false;
		if (flag) {
			puts("Yes");
		}
		else {
			puts("No");
		}
	}
	return 0;
}
