#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k;
const ll MAX_N = 2e5;
const ll INF = 1e10;

vector<ll> Rank;
vector<ll> tmp;
vector<ll> sa;
vector<ll> lcp;

bool comp_sa(ll i, ll j) {
	if (Rank[i] != Rank[j])return Rank[i] < Rank[j];
	else {
		ll ri = i + k <= n ? Rank[i + k] : -1;
		ll rj = i + k <= n ? Rank[j + k] : -1;
		return ri < rj;
	}
}

void construct_sa(string s) {
	n = s.length();
	Rank.resize(n + 1);
	tmp.resize(n + 1);
	sa.resize(n + 1);

	for (ll i = 0; i <= n; ++i) {
		sa[i] = i;
		Rank[i] = i < n ? s[i] : -1;
	}

	for (k = 1; k <= n; k *= 2) {
		sort(sa.begin(), sa.end(), comp_sa);
		tmp[sa[0]] = 0;
		for (ll i = 1; i <= n; ++i) {
			tmp[sa[i]] = tmp[sa[i - 1]] + (comp_sa(sa[i - 1], sa[i]) ? 1 : 0);
		}
		Rank = tmp;
	}
}

void construct_lcp(string s) {
	n = s.length();
	lcp.resize(n + 1);
	for (ll i = 0; i <= n; ++i)Rank[sa[i]] = i;

	ll h = 0;
	lcp[0] = 0;
	for (ll i = 0; i < n; ++i) {
		ll j = sa[Rank[i] - 1];
		if (h > 0)--h;
		for (; j + h < n && i + h < n; ++h) {
			if (s[j + h] != s[i + h])break;
		}
		lcp[Rank[i] - 1] = h;
	}
}

class SegmentTree {
private:
	ll n;
	vector<ll> node;

public:
	// 元配列 v をセグメント木で表現する
	SegmentTree(vector<ll> v) {
		// 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
		// セグメント木全体で必要なノード数は 2n-1 個である
		ll sz = v.size();
		n = 1; while (n < sz) n *= 2;
		node.resize(2 * n - 1, INF);

		// 最下段に値を入れたあとに、下の段から順番に値を入れる
		// 値を入れるには、自分の子の 2 値を参照すれば良い
		for (ll i = 0; i < sz; i++) node[i + n - 1] = v[i];
		for (ll i = n - 2; i >= 0; i--) node[i] = min(node[2 * i + 1], node[2 * i + 2]);
	}

	void update(ll x, ll val) {
		// 最下段のノードにアクセスする
		x += (n - 1);

		// 最下段のノードを更新したら、あとは親に上って更新していく
		node[x] = val;
		while (x > 0) {
			x = (x - 1) / 2;
			node[x] = min(node[2 * x + 1], node[2 * x + 2]);
		}
	}

	ll getmin(ll a, ll b, ll k = 0, ll l = 0, ll r = -1) {
		// 最初に呼び出されたときの対象区間は [0, n)
		if (r < 0) r = n;

		// 要求区間と対象区間が交わらない -> 適当に返す
		if (r <= a || b <= l) return INF;

		// 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
		if (a <= l && r <= b) return node[k];

		// 要求区間が対象区間の一部を被覆 -> 子について探索を行う
		// 左側の子を vl ・ 右側の子を vr としている
		// 新しい対象区間は、現在の対象区間を半分に割ったもの
		ll vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
		ll vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);
		return min(vl, vr);
	}
};

int main() {
	string s;
	cin >> s;
	ll n = s.size();
	map<char, ll> m;
	for (char c : s)++m[c];
	ll ans = n * (n - 1) / 2;
	for (auto p : m) {
		ans -= p.second * (p.second - 1) / 2;
	}
	cout << ans + 1 << endl;
}
