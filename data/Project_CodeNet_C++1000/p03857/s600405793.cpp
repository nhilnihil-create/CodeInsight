
#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
#include<queue>
#include<list>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<cstdio>
#include <iomanip>

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i<=b;i++)
#define fore(i,a) for(auto &i:a)


using namespace std;
typedef long long ll;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9 + 7;
const ll INF = 1e9;
const ll MAXN = 1e9;

struct union_find {
	vector<int> par, r;

	union_find(int n) {
		par.resize(n);
		r.resize(n);
		for (int i = 0; i < n; i++) par[i] = i, r[i] = 0;
	}

	int find(int x) {
		if (par[x] == x) return x;
		else return find(par[x]);
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (r[x] < r[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (r[x] == r[y]) r[x]++;
		}
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

int main()
{
	int n, k, l;
	cin >> n >> k >> l;

	union_find road(n), train(n);
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		road.unite(a, b);
	}
	for (int i = 0; i < l; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		train.unite(a, b);
	}

	vector<pair<int, int> > com(n);
	map<pair<int, int>, int> s;
	for (int i = 0; i < n; i++) {
		com[i].first = road.find(i);
		com[i].second = train.find(i);
		s[com[i]]++;
	}

	for (int i = 0; i < n; i++) {
		cout << s[com[i]] << " ";
	}printf("\n");

		return 0;
}