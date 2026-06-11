#include <bits/stdc++.h>

template<int Max>
class TreeUF
{
public:
	TreeUF() = default;

	TreeUF(int N)
	{
		for (int i = 0; i < N; i++)
			par[i] = i;
	}

	void setSize(int n)
	{
		for (int i = 0; i < n; i++)
			par[i] = i;
	}

	int root(int x)
	{
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(int x, int y)
	{
		int rx = root(x);
		int ry = root(y);
		if (rx == ry) return;
		par[rx] = ry;
	}

	bool same(int x, int y)
	{
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}

private:
	int par[Max];

};

int n, k, l;
TreeUF<200005> road;
TreeUF<200005> train;
std::map<std::pair<int, int>, int> cnt;
int main()
{
	std::cin >> n >> k >> l;

	road.setSize(n);
	train.setSize(n);
	for (int i = 0; i < k; ++i) {
		int p, q;
		std::cin >> p >> q;
		--p, --q;
		road.unite(p, q);
	}

	for (int i = 0; i < l; ++i) {
		int r, s;
		std::cin >> r >> s;
		--r, --s;
		train.unite(r, s);
	}

	for (int i = 0; i < n; ++i)
		++cnt[std::make_pair(road.root(i), train.root(i))];

	for (int i = 0; i < n; ++i) {
		std::cout << cnt[std::make_pair(road.root(i), train.root(i))];
		if (i != n - 1)
			std::cout << " ";
		else
			std::cout << std::endl;
	}

	return 0;
}
