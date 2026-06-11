#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()

vector<int> G[100010];
deque<int> ans;
bool arr[100010];

void dfs(int i, bool fr) {
	arr[i] = 1;

	for (int x : G[i]) {
		if (arr[x])continue;
		if (fr)
			ans.push_front(x);
		else
			ans.push_back(x);
		dfs(x, fr);
		return;
	}
}

int main(){
	int N, M, a, b;
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	ans.push_back(0);
	dfs(0, 0);
	dfs(0, 1);
	cout << ans.size() << endl;
	while (!ans.empty()) {
		cout << ans.front() + 1 << " ";
		ans.pop_front();
	}
	cout << endl;
}