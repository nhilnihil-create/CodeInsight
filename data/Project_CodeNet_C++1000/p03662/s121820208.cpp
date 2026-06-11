#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <queue>

typedef long long int ll;

#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)
#define REP(i,n) FOR(i,n,0)
#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;

using namespace std;

vector<int> node[100005];
vector<int> route;
bool U[100005];

bool dfs(int n, int g)
{
	if (U[n])return false;
	U[n] = true;
	route.push_back(n);
	if (n == g)
	{
		return true;
	}
	REP(i, node[n].size())
	{
		if (dfs(node[n][i], g))
		{
			return true;
		}
	}
	route.pop_back();
	return false;
}

int main()
{

	int N;
	cin >> N;

	REP(i, N - 1)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	fill(U, U + N, false);
	dfs(0, N - 1);

	int fn = route[(route.size() + 1) / 2 - 1];
	int sn = route[(route.size() + 1) / 2];
	REP(i, node[fn].size())
	{
		if (node[fn][i] == sn)
		{
			node[fn].erase(node[fn].begin() + i);
			break;
		}
	}

	int fNum = 0;
	queue<int> q;
	q.push(0);
	fill(U, U + N, false);
	while (!q.empty())
	{
		fNum++;
		int n = q.front();
		q.pop();
		U[n] = true;
		REP(i, node[n].size())
		{
			int c = node[n][i];
			if (U[c])continue;
			q.push(c);
		}
	}

	if (fNum > N - fNum)
	{
		cout << "Fennec";
	}
	else
	{
		cout << "Snuke";
	}

	return 0;
}