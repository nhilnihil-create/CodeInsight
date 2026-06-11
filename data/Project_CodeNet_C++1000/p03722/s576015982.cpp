//#include "bits/stdc++.h"

#define _USE_MATH_DEFINES
#include<cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iterator>
#include<iomanip>
#include<unordered_set>
#include<bitset>
#include<complex>

using namespace std;

#define rep(i,a,b) for(int i=(a), i##_len=(b);i<i##_len;i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)

#define int ll
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

//typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector< vector<int> > mat;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

struct edge
{
	int s, t, cost;
	edge(int s, int t, int cost) :s(s), t(t), cost(cost) {}
	edge() :edge(-1, -1, -1) {}
};

vector<edge> G[1010];
edge edges[2010];
int d[1010];
bool reach[1010];
int V, E;

void shortest_path(int s)
{
	rep(i, 0, V)d[i] = INF;
	d[s] = 0;

	for (int k = 0;; k++)
	{
		bool update = false;

		rep(i, 0, E)
		{
			if (d[edges[i].s] != INF && d[edges[i].t] > d[edges[i].s] + edges[i].cost)
			{
				d[edges[i].t] = d[edges[i].s] + edges[i].cost;
				if (k == V + 1)
				{
					if (reach[edges[i].t])
					{
						d[V - 1] = INF;
					}
					return;
				}
				update = true;
			}
		}

		if (!update)
		{
			break;
		}
	}
}

void dfs(int v)
{
	if (reach[v])return;
	reach[v] = true;
	for (auto e : G[v])
	{
		dfs(e.t);
	}
}

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> V >> E;
	int a, b, c;
	rep(i, 0, E)
	{
		cin >> a >> b >> c;
		a--, b--;
		edges[i] = edge(a, b, -c);
		G[b].push_back(edge(b, a, -c));
	}

	dfs(V - 1);
	shortest_path(0);

	if (d[V - 1] == INF)
	{
		cout << "inf" << endl;
	}
	else
	{
		cout << -d[V - 1] << endl;
	}

	return 0;
}