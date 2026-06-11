#include <bits/stdc++.h>
#define len(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmax(x, v) x = max((x), (v))
#define chmin(x, v) x = min((x), (v))
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int nbElem; cin >> nbElem;
	ll dpt, prev;
	vector<ll> diff;
	for (int i = 0; i < nbElem; ++i) {
		ll cur; cin >> cur;
		if (i == 0) dpt = cur;
		else diff.push_back(cur-prev);
		prev = cur;
	}
	vector<ll> id(nbElem-1);
	iota(all(id), 0);
	auto perm = id;
	int nbSwap; ll expo;
	cin >> nbSwap >> expo;
	for (int iSwap = 0; iSwap < nbSwap; ++iSwap) {
		int idx; cin >> idx;
		swap(perm[idx-2], perm[idx-1]);
	}
	auto comp = [&] (vector<ll> p, vector<ll> q) {
		vector<ll> r = p;
		for (int i = 0; i < len(p); ++i) {
			r[i] = q[p[i]];
		}
		return r;
	};
	auto get = [&] (ll x, auto self) {
		if (x == 0) return id;
		vector<ll> r = self(x/2, self);
		r = comp(r,r);
		if (x & 1) r = comp(perm, r);
		return r;
	};
	diff = comp(get(expo, get), diff);
	for (int i = 0; i < nbElem; ++i) {
		if (i) dpt += diff[i-1];
		cout << dpt << "\n";
	}
}
