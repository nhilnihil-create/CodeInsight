#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

typedef long long ll;

template <class Monoid1, class Monoid2> struct LazySegTree {
	int N;
	vector<Monoid1> node;
	vector<Monoid2> lazy;
	std::function<Monoid1(Monoid1, Monoid1)> operation1;
	std::function<Monoid2(Monoid2, Monoid2)> operation2;
	std::function<Monoid1(Monoid1, Monoid2)> operation3;
	std::function<Monoid2(Monoid2, int)> operation4;
	Monoid1 unit1;//Monoid1の単位元
	Monoid2 unit2;//Monoid2の単位元

	LazySegTree(vector<Monoid1>& data,
		std::function<Monoid1(Monoid1, Monoid1)> op1,
		std::function<Monoid2(Monoid2, Monoid2)> op2,
		std::function<Monoid1(Monoid1, Monoid2)> op3,
		std::function<Monoid2(Monoid2, int)> op4,
		Monoid1 U1, Monoid2 U2) {
		//データ　演算1~4　単位元1~2
		operation1 = op1;
		operation2 = op2;
		operation3 = op3;
		operation4 = op4;
		unit1 = U1;
		unit2 = U2;
		int size = data.size();
		N = 1;
		while (N < size)N <<= 1;
		node.resize(2 * N - 1, unit1);
		lazy.resize(2 * N - 1, unit2);

		for (int i = 0; i < size; i++) {
			node[i + N - 1] = data[i];
		}

		for (int i = N - 2; i >= 0; i--) {
			node[i] = operation1(node[i * 2 + 1], node[i * 2 + 2]);
		}
	}

	//番号kのデータを伝播させる。
	void eval(int k, int l, int r) {
		if (lazy[k] == unit2)return;
		node[k] = operation3(node[k], operation4(lazy[k], r - l));
		if (r - l > 1) {
			//子を持ってる
			lazy[2 * k + 1] = operation2(lazy[2 * k + 1], lazy[k]);
			lazy[2 * k + 2] = operation2(lazy[2 * k + 2], lazy[k]);
		}
		lazy[k] = unit2;
	}

	void update(Monoid2 val, int idx, int a, int b, int l = 0, int r = -1) {
		//[a, b)
		if (r < 0)r = N;
		eval(idx, l, r);
		//範囲外なら何もしない
		if (b <= l || r <= a)return;
		if (a <= l && r <= b) {
			//完全に被覆してるのなら、遅延配列を更新して評価。
			lazy[idx] = operation3(lazy[idx], val);
			eval(idx, l, r);
			return;
		}
		update(val, idx * 2 + 1, a, b, l, (l + r) / 2);
		update(val, idx * 2 + 2, a, b, (l + r) / 2, r);
		node[idx] = operation1(node[idx * 2 + 1], node[idx * 2 + 2]);
	}

	void update(Monoid2 val, int a, int b) {
		//[a, b)
		update(val, 0, a, b, 0, -1);
	}

	Monoid1 getval(int a, int b, int idx, int l, int r = -1) {
		eval(idx, l, r);
		//[a, b)を求める。　使い方はgetval(a, b, );
		if (r == -1)r = N;
		if (b <= l || r <= a)return unit1;
		if (a <= l && r <= b)return node[idx];
		Monoid1 left = getval(a, b, idx * 2 + 1, l, (l + r) / 2);
		Monoid1 right = getval(a, b, idx * 2 + 2, (l + r) / 2, r);
		return operation1(left, right);
	}

	Monoid1 getval(int a, int b) {
		//ラッパー。
		return getval(a, b, 0, 0, -1);
	}
};

int n, m;
ll a[100000 + 100];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> a[i], a[i]--;
	vector<pair<ll, ll>> tmp(m);
	LazySegTree<pair<ll, ll>, pair<ll, ll>> lst(tmp,
		[](pair<ll, ll> l, pair<ll, ll> r) {
		pair<ll, ll> ret;
		ret.first= l.first + r.first, ret.second = l.second + r.second;
		return ret;
	},
		[](pair<ll, ll> l, pair<ll, ll> r) {
		pair<ll, ll> ret;
		ret.first = l.first + r.first, ret.second = l.second + r.second;
		return ret;
	}, [](pair<ll, ll> l, pair<ll, ll> r) {
		pair<ll, ll> ret;
		ret.first = l.first + r.first, ret.second = l.second + r.second;
		return ret;
	},
		[](pair<ll, ll> l, int x) {
		l.first *= x, l.second *= x;
		return l;
	}, make_pair(0, 0), make_pair(0, 0));
	
	ll start = 0;
	for (int i = 1; i < n; i++) {
		if ((m + a[i] - a[i - 1]) % m >= ((m + a[i] - 0) % m) + 1) {
			start += ((m + a[i] - 0) % m) + 1;
		}
		else {
			start += (m + a[i] - a[i - 1]) % m;
		}
	}

	for (int i = 1; i < n; i++) {
		lst.update(make_pair(0, (m + a[i] - a[i - 1]) % m), 0, m - 1);
		if ((m + a[i] - a[i - 1]) % m == 1) {
			//何もしない
		}else if (((a[i] + 1) % m) - a[i - 1] > 0) {
			lst.update(make_pair(-1, 0), a[i - 1] + 1, a[i]);
			lst.update(make_pair(a[i] - a[i - 1] - 1, 0), a[i], a[i] + 1);
		}
		else if (a[i] + 1 == m) {
			lst.update(make_pair(-1, 0), a[i - 1] + 1, a[i]);
		}
		else if (a[i] - a[i - 1] < 0) {
			lst.update(make_pair(-1, 0), a[i - 1] + 1, m - 1);
			lst.update(make_pair(-1, 0), 0, a[i]);
			lst.update(make_pair(m + a[i] - a[i - 1] - 1, 0), a[i], a[i] + 1);
		}
	}

	ll ans = start;
	
	for (int i = 0; i < m - 1; i++) {
		auto tmp = lst.getval(i, i + 1);
		start += tmp.first;
		ans = min(ans, start);
	}
	cout << ans << endl;
	return 0;
}