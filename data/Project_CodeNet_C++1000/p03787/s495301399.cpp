#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()

vector<int> G[100010];
short arr[100010];

ll cnt;

bool dfs(int c, int p, short v) {
	bool jd = 0;
	for (int i : G[c]) {
		if (i == p)continue;
		if (arr[i] == 3 - v) {
			jd = 1;
			continue;
		}
		if (arr[i] == v) {
			continue;
		}
		arr[i] = v;
		cnt++;
		if (dfs(i, c, 3 - v))jd = 1;
	}
	return jd;
}

int main() {
	ll N, M, a, b;
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	ll lef = N * N, ed = 0;
	ll cone = 0, alc = 0;
	bool rt;
	for (int i = 0;i < N;i++) {
		if (arr[i])continue;
		cnt = 1;
		arr[i] = 2;
		rt = dfs(i, -1, 1);
		if (cnt == 1)continue;
		if (rt) {
			alc++;
			ed += cnt;
		}
		else {
			cone++;
			alc++;
			ed += cnt;
		}
	}
	lef -= ed * ed;
	lef += alc * alc + cone * cone;
	cout << lef << endl;
}