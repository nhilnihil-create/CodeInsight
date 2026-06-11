
#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <string>
#include <bitset>
#include <list>
#include <set>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <functional>
#include <queue>
#include <regex>
#include <cassert>
#include <map>
// #include "bits/stdc++.h"

using namespace std;



namespace {
#define rep(i, N, M) for(int i=N, i##_len=(M); i<i##_len; ++i)
#define rep_skip(i, N, M, ...) for(int i=N, i##_len=(M); i<i##_len; i+=(skip))
#define rrep(i, N, M)  for(int i=(M)-1, i##_len=(N-1); i>i##_len; --i)
#define pb push_back


	typedef long long ll;
	typedef unsigned long long ull;
	typedef pair<ll, ll> pll;
	typedef tuple<ll, ll, ll> tll;
	typedef tuple<ll, ll, ll, ll> tll4;
	typedef vector<ll> vll;
	typedef vector<vll> vvll;
	typedef vector<pll> vpll;
	typedef vector<bool> vb;
	typedef vector<vb> vvb;
	typedef vector<string> vs;
	typedef priority_queue<ll> pqll;
	typedef priority_queue<pll, vector<pll>> pqpll;
	typedef priority_queue<ll, vll, greater<ll>> pqll_greater;
	typedef priority_queue<pll, vector<pll>, greater<pll>> pqpll_greater;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define vec(a) vector<a>
#define perm(c) sort(all(c));for(bool c##perm=1;c##perm;c##perm=next_permutation(all(c)))


	template<class T, class S>
	T atbit(T n, S i) {
		return (n >> i) % i;
	}

	template<class T>
	T getbit(T i) {
		return 1LL << i;
	}

	constexpr ll POW(ll n, ll m) {
		ll res = 1;
		rep(i, 0, m) {
			res *= n;
		}
		return res;
	}

	vll getDivisors(ll n) {
		vll res;
		ll i = 1;

		for (; i*i < n; i++) {
			if (n%i == 0) {
				res.push_back(i);
				res.push_back(n / i);
			}
		}
		if (i*i == n)res.push_back(i);
		sort(res.begin(), res.end());
		return res;
	}

	vll getDivisors(ll n, ll m) {
		if (n > m) swap(n, m);
		vll res;
		ll i = 1;

		for (; i*i < n; i++) {
			if (n%i == 0) {
				if (m%i == 0) res.push_back(i);
				if (m % (n / i) == 0) res.push_back(n / i);
			}
		}
		if (i*i == n) if (m%i == 0) res.push_back(i);
		sort(res.begin(), res.end());
		return res;
	}


	ll gcd(ll a, ll b) {
		if (a%b == 0) return b;
		else return gcd(b, a%b);
	}

	template<
		typename Inputs,
		typename Functor,
		typename T = typename Inputs::value_type>
		void sort_by(Inputs& inputs, Functor f) {
		std::sort(std::begin(inputs), std::end(inputs),
			[&f](const T& lhs, const T& rhs) { return f(lhs) < f(rhs); });
	}

	template<int I>
	vll proj(vpll v) {
		vll res(v.size());
		rep(i, 0, v.size()) {
			if (!I) res[i] = v[i].first;
			else res[i] = v[i].second;
		}
		return res;
	}


	template<int I, class T>
	vll proj(T v) {
		vll res(v.size());
		rep(i, 0, v.size()) {
			res[i] = get<I>(v[i]);
		}
		return res;
	}
	vector<pll >prime_factorize(ll n) {
		vector<pll> res;
		for (ll p = 2; p*p <= n; ++p) {
			if (n%p != 0)continue;
			ll num = 0;
			while (n%p == 0) { ++num; n /= p; }
			res.push_back({ p,num });
		}
		if (n != 1) res.push_back(make_pair(n, 1));
		return res;
	}

}

ll MOD = 1000000007;
ll INF = 1LL << 60;
string alph = "abcdefghijklmnopqrstuvwxyz";

bool less_str(string& a, const string& b){
	if (a.size() > b.size()) {
		return false;
	}
	else if (a.size() == b.size() && a > b) {
		return false;
	}
	return true;
};
int main() {
	string A;
	cin >> A;

	ll n = A.size();
	vector<string> dp(26, "");

	rep(c, 0, 26) {
		if(A.back() != alph[c]) dp[c]=alph[c];
		else dp[c] = alph.substr(c, 1) + 'a';
	}

	rrep(i, 0, n) {
		int ch = A[i] - 'a';
		dp[ch] = A.substr(i,1) +  *min_element(all(dp), less_str);
	}
	cout << *min_element(all(dp), less_str);

	return 0;
}
