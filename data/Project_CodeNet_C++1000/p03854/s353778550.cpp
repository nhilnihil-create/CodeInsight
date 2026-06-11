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
char c[30][30];
char atari[30];
ll dp[101];

//long longしか使わない
//素数は1より大きい
//lower_boundは指定したkey以上の要素の一番左のイテレータをかえす
//upper_boundは指定したkeyより大きい要素の一番左のイテレータをかえす
int main() {
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	ll res = 0;
	while (res < s.length()) {
		if (s[res] == 'r' && s[res + 1] == 'e' && s[res + 2] == 'm' && s[res + 3] == 'a' && s[res + 4] == 'e' && s[res + 5] == 'r' && s[res + 6] == 'd') {
			res += 7;
		}
		else if (s[res] == 'r' && s[res + 1] == 'e' && s[res + 2] == 's' && s[res + 3] == 'a' && s[res + 4] == 'r' && s[res + 5] == 'e') {
			res += 6;
		}
		else if (s[res] == 'e' && s[res + 1] == 's' && s[res + 2] == 'a' && s[res + 3] == 'r' && s[res + 4] == 'e') {
			res += 5;
		}
		else if (s[res] == 'm' && s[res + 1] == 'a' && s[res + 2] == 'e' && s[res + 3] == 'r' && s[res + 4] == 'd') {
			res += 5;
		}
		else {
			break;
		}
	}
	if (res == s.length()) {
		puts("YES");
	}
	else {
		puts("NO");
	}
	return 0;
}
