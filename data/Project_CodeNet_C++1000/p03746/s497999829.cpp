#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
#include<set>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll, ll> pll;
//int dx[4] = { 1,0,0,-1 };
//int dy[4] = { 0,1,-1,0 };
#define MOD 1000000007
#define ARRAY_MAX 100005

const int INF = 1e9 + 7;

int n, m;
vector<int> ans;
vector<int> G[ARRAY_MAX];
bool visited[ARRAY_MAX];



void dfs(int now) {

	visited[now] = true;
	ans.push_back(now);

	for (int i = 0; i < G[now].size(); i++)
	{
		if (visited[G[now][i]] == false)
		{
			return dfs(G[now][i]);
		}
	}


}

int main() {


	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
		//1-index
	}

	dfs(1);
	reverse(ans.begin(), ans.end());
	ans.pop_back();
	dfs(1);

	cout << ans.size() << endl;

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}
