#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i, s, e) for (int i = (s); i <= (e); i++)
int n;
int k;
int l;


struct UnionFind
{
	vector<int> par_;
	vector<int> rank_;

	void init(int size)
	{
		par_.resize(size, 0);
		rank_.resize(size, 0);
		for (int i = 0; i < size; i++)
		{
			par_[i] = i;
			rank_[i] = 0;
		}
	}
	int root(int x)
	{
		return par_[x] == x ? x : par_[x] = root(par_[x]);
	}

	bool unite(int x, int y)
	{
		x = root(x);
		y = root(y);
		if (x == y)
			return true;

		if (rank_[x] < rank_[y])
		{
			par_[x] = y;
		}
		else
		{
			par_[y] = x;
			if (rank_[x] == rank_[y])
				rank_[x]++;
		}
		return false;
	}
	bool same(int x, int y)
	{
		return root(x) == root(y);
	}
};

int main()
{

	cin >> n >> k >> l;

	UnionFind road,train;
	road.init(n);
	train.init(n);

	rep(i, 1, k)
	{
		int p, q;
		cin >> p >> q;
		p--;q--;
		road.unite(p,q);
	}
	rep(i, 1, l)
	{
		int p, q;
		cin >> p >> q;
		p--;q--;
		train.unite(p,q);
	}

	typedef pair<int,int> P;
	typedef pair<P,int> P2;
	vector<P2> vec;

	rep(i,0,n - 1)
	{
		road.root(i);
		train.root(i);
	}

	rep(i,0,n-1)
	{
		vec.push_back(P2(P(road.par_[i],train.par_[i]),i));
	}

	sort(vec.begin(),vec.end());
	vector<int> memo;
	vector<int> cou(n,0);

	int c = 1;
	memo.push_back(vec[0].second);

	rep(i,1,n - 1)
	{
		if(vec[i - 1].first.first == vec[i].first.first && vec[i - 1].first.second == vec[i].first.second)
		{
			c++;
		}
		else
		{
			for(int m : memo)
			{
				cou[m] = c;
			}
			c = 1;
			memo.resize(0);
		}
		memo.push_back(vec[i].second);
	}

	for(int m : memo)
	{
		cou[m] += c;
	}
	c = 1;
	for(int ans : cou)
	{
		cout << ans << endl;
	}
	return 0;


}
