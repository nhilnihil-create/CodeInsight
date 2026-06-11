#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
#define ll long long
#define MOD 1000000007

vector<int> T[100010];
int p[100010], a[100010], d[100010];

void dep(int x, int v) {
	d[x] = v;
	for (int i : T[x]) {
		if (i == x)continue;
		dep(i, v + 1);
	}
}

int main(){
	int N, K, sc = 0;
	cin >> N >> K;
	for (int i = 1;i <= N;i++) {
		cin >> a[i];
		if (i == 1 && a[1] != 1) {
			sc++;
			a[1] = 1;
		}
		T[a[i]].push_back(i);
	}

	dep(1, 0);

	priority_queue<tuple<int,int,int>> Q;
	for (int i = 1;i <= N;i++) {
		if (T[i].size() == 0) {
			Q.push(make_tuple(d[i], 1, i));
		}
	}

	int f, g;
	while (!Q.empty()) {
		tie(ignore, f, g) = Q.top();
		Q.pop();
		if (g == 1)continue;
		if (p[g] >= f) {
			continue;
		}
		p[g] = f;
		if (f == K) {
			if (a[g] == 1)continue;
			Q.push(make_tuple(d[a[g]], 1, a[g]));
			sc++;
		}
		else {
			Q.push(make_tuple(d[a[g]], f + 1, a[g]));
		}
	}
	cout << sc << endl;
}