#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod998 = 998244353;
const ll intmax = 2147483647;
const ll llmax = 9223372036854775807;
const char sp = ' ';

int N;
ll res;
vector<ll>v, s;

int main() {
	cin >> N;
	int x;
	cin >> x;
	v.push_back(x);
	for (int i = 1; i < N; i++) {
		char c;
		cin >> c >> x;
		if (c == '+') {
			v.back() += x;
		}
		else {
			v.push_back(x);
			v.push_back(0);
		}
	}
	s = v;
	for (int i = v.size() - 2; i >= 0; i--) {
		s[i] += s[i + 1];
	}
	res = -llmax;
	ll t = 0;
	for (int i = 0; i < v.size(); i++) {
		if (i & 1) {
			if (i + 2 < v.size()) {
				res = max(res, t - v[i] - v[i + 1] + s[i + 2]);
			}
			t -= v[i];
		}
		else {
			t += v[i];
		}
	}
	cout << max(res, t) << endl;
}