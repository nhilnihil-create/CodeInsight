#include "bits/stdc++.h"
using namespace std;

#define MAX 100002

int n;
int m;

vector<int> v;

struct st {
	int l;
	int r;
	int id;
};

vector<st> query;

vector<int> ev[MAX];
vector<int> en[MAX];

vector<pair<int, int> > vv;

int calc(int i, int x) {
	if (x != -1) {
		if (vv[i].first <= vv[i].second) {
			if (vv[i].first <= x&&x <= vv[i].second) {
				return vv[i].second - x;
			}
		}
		else {
			if (vv[i].first <= x || x <= vv[i].second) {
				return (vv[i].second + m - x)%m;
			}
		}
	}
	return (vv[i].second + m - vv[i].first) % m;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		a--;
		v.push_back(a);
	}
	for (int i = 0; i+1 < v.size(); i++) {
		int a = v[i];
		int b = v[i + 1];
		if (a <= b) {
			query.push_back({ a,b,i });
		}
		else {
			query.push_back({ a,m - 1,i });
			query.push_back({ 0, b, i });
		}
		vv.push_back(make_pair(a, b));
	}
	for (int i = 0; i < query.size(); i++) {
		int I = query[i].id;
		if (vv[I].first == vv[I].second)continue;
		if (vv[I].first > vv[I].second) {
			if (query[i].l) {
				ev[query[i].l].push_back(query[i].id);
			}
			en[query[i].r].push_back(query[i].id);
			continue;
		}
		ev[query[i].l].push_back(query[i].id);
		en[query[i].r].push_back(query[i].id);
	}
	long long int sum = 0;
	long long int mv = 0;
	for (int i = 0; i < vv.size(); i++) {
		if (vv[i].first > vv[i].second) {
			sum += calc(i, 0)+1;
			mv++;
		}
		else {
			sum += calc(i, -1);
		}
	}
	long long int ans = sum;
	for (int i = 0; i < m; i++) {
		sum -= mv;
		ans = min(ans, sum + mv);
		for (int j = 0; j < ev[i].size(); j++) {
			sum -= calc(ev[i][j], -1);
			sum += calc(ev[i][j], i);
			mv++;
		}
		for (int j = 0; j < en[i].size(); j++) {
			sum -= calc(en[i][j], i);
			mv--;
			sum += calc(en[i][j], -1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}