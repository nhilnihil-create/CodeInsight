#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define modulo 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60


vector<int> V[100001];
vector<int> L; // goal から start までの道のり
int color[100001];
bool check[100001]; // dfsのためのマーカー

bool dfs(int start,int goal) {
	check[start] = true;
	bool flag = false;
	if (start == goal) {
		flag = true;
	}
	else {
		for (int x : V[start]) {
			if (!check[x]) flag = (flag || dfs(x, goal));
		}
	}
	if (flag) L.push_back(start);
	return flag;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	
	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	dfs(1, N);
	reverse(L.begin(), L.end());
	
	/*
	cout << L.size() << endl;
	for (int i = 0; i < L.size(); i++) cout << L[i] << " ";
	*/


	queue<int> Q;
	for (int i = 0; i < L.size(); i++) {
		if (2 * i < L.size()) {
			color[L[i]] = 1; // 黒
			Q.push(L[i]);
		}
		else color[L[i]] = 2; // 白
	}
	
	int ans = Q.size();
	while (!Q.empty()) {
		int pos = Q.front();
		Q.pop();

		for(int x : V[pos]) {
			if (color[x] == 0) {
				ans++;
				Q.push(x);
				color[x] = 1;
			}
		}
	}

	// cout << ans << endl;

	if (ans > N / 2) cout << "Fennec" << endl;
	else cout << "Snuke" << endl;
	

	return 0;
}