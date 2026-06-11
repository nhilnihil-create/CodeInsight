
#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const double pi = acos(-1);
#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)
#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME
#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	REP(i, v.size()) { if (i)os << " "; os << v[i]; }return os;
}
template<typename T> ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
	REP(i, v.size()) { if (i)os << endl; os << v[i]; }return os;
}

const ll INF = 1LL << 60;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	string s;
	vector<ll> v[26];
	string ss = "abcdefghijklmnopqrstuvwxyz";

	cin >> s;

	REP(i, s.size()) {
		v[s[i] - 'a'].push_back(i);
	}

	vector<ll> vv(26, 0);
	stack<pair<ll, ll>> st;
	ll e = s.size() - 1;
	ll now = 1;
	ll c = 0;
	ll k = 0;

	RREP(i, s.size()) {
		if (vv[s[i] - 'a'] != now) {
			vv[s[i] - 'a']++;
			c++;
		}

		if (c == 26) {
			st.push(make_pair(i, e));
			e = i - 1;
			now++;
			c = 0;
			k++;
		}

		if (i == 0) {
			st.push(make_pair(0, e));
			break;
		}
	}

	ll point = -1;

	REP(i, k + 1) {
		pair<ll, ll> p = st.top();
		st.pop();
		REP(j, 26) {
			vector<ll>::iterator it = upper_bound(v[j].begin(), v[j].end(), point);
			if (it == v[j].end() || *it < p.first || *it > p.second) {
				cout << ss[j];
				if (it != v[j].end()) {
					point = *it;
				}
				break;
			}
		}
	}

	cout << endl;
}