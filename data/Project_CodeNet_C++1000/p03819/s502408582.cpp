#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
struct SegTree {
	int n;
	std::vector<int> data;
	SegTree (int n_) {
		for (n = 1; n < n_; n <<= 1);
		data.resize(n << 1);
	}
	void add(int i, int val) {
		for (i += n; i; i >>= 1) data[i] += val;
	}
	int sum(int l, int r) {
		int res = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (r & 1) res += data[--r];
			if (l & 1) res += data[l++];
		}
		return res;
	}
};
struct Points2D {
	std::vector<std::pair<int, int> > pts;
	struct Query {
		int x1;
		int x2;
		int y1;
		int y2;
		int *res;
	};
	std::vector<Query> queries;
	void add(std::pair<int, int> pt) {
		pts.push_back(pt);
	}
	void query(Query query) {
		queries.push_back(query);
	}
	void calculate() {
		int sz = queries.size();
		for (int i = 0; i < sz; i++) {
			*queries[i].res = 0;
			queries.push_back({queries[i].x1, queries[i].x2, queries[i].y2, 1, queries[i].res});
			queries[i].y2 = -1;
		}
		std::sort(pts.begin(), pts.end(), [] (auto &a, auto &b) { return a.second < b.second; });
		std::sort(queries.begin(), queries.end(), [] (Query &a, Query &b) { return a.y1 < b.y1; });
		int n = pts.size();
		int head = 0;
		SegTree tree(300001);
		for (auto &i : queries) {
			while (head < n && pts[head].second < i.y1) tree.add(pts[head++].first, 1);
			*i.res += i.y2 * tree.sum(i.x1, i.x2);
		}
	}
};

int main() {
	int n = ri(), m = ri();
	int l[n], r[n];
	Points2D points;
	for (int i = 0; i < n; i++) l[i] = ri(), r[i] = ri(), points.add({l[i], r[i]});
	std::vector<int> res(m, 0);
	for (int i = 1; i <= m; i++)
		for (int j = 0; j < m; j += i) points.query({j + 1, std::min(m + 1, j + i), j + 1, std::min(m + 1, j + i), &res[i - 1]});
	points.calculate();
	for (int i = 1; i <= m; i++) std::cout << n - res[i - 1] << std::endl;
	return 0;
}
