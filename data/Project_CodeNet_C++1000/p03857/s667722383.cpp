#include<iostream>
#include<cstdio>
#include<math.h>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
#include<map>
#define INF 999999
#define EPS 1.0e-6

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;

int n, k, l;
vector<int> road[210000];
vector<int> train[210000];
int flag[210000];
P memo[210000];

void dfs_r(int s,int c)
{
	flag[s] = 1;
	memo[s].first = c;
	for (int i = 0; i < road[s].size(); i++) {
		if (flag[road[s][i]] == 0) {
			dfs_r(road[s][i],c);
		}
	}
}

void dfs_t(int s, int c)
{
	flag[s] = 1;
	memo[s].second = c;
	for (int i = 0; i < train[s].size(); i++) {
		if (flag[train[s][i]] == 0) {
			dfs_t(train[s][i], c);
		}
	}
}

void scc() {
	fill(flag, flag + n, 0);
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (flag[i] == 0) {
			dfs_r(i, c);
			c++;
		}
	}
	c = 0;
	fill(flag, flag + n, 0);
	for (int i = 0; i < n; i++) {
		if (flag[i] == 0) {
			dfs_t(i, c);
			c++;
		}
	}
}


int main()
{
	cin >> n >> k >> l;
	int a,b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		a--; b--;
		road[a].push_back(b);
		road[b].push_back(a);
	}
	for (int i = 0; i < l; i++) {
		cin >> a >> b;
		a--; b--;
		train[a].push_back(b);
		train[b].push_back(a);
	}
	scc();
	map<P,int> mp;
	for (int i = 0; i < n; i++) {
		//cout << memo[i].first << " "<<memo[i].second << endl;
		if (mp[memo[i]] != 0)mp[memo[i]]++;
		else mp[memo[i]] = 1;
	}
	for (int i = 0; i < n-1; i++) {
		cout << mp[memo[i]] << " ";
	}
	cout << mp[memo[n - 1]] << endl;

	return 0;
}