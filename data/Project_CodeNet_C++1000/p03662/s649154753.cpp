#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> T(100000);

int N, rd, md = -1, fen, snu, cnt = 0;

void fdfs(int c, int p, int dis) {
	if (c == N - 1) {
		rd = dis;
		md = rd / 2;
	}
	else if (md < 0) {
		int C = T[c].size();
		for (int i = 0;i < C;i++) {
			if (T[c][i] == p)
				continue;
			fdfs(T[c][i], c, dis + 1);
			if (md >= 0) break;
		}
	}
	if (dis == md + 1) {
		fen = p;
		snu = c;
	}
}

void sdfs(int c, int p) {
	cnt++;
	int C = T[c].size();
	for (int i = 0;i < C;i++) {
		if (T[c][i] == p)
			continue;
		sdfs(T[c][i], c);
	}
}

int main() {
	int a, b;
	cin >> N;
	for (int i = 0;i < N - 1;i++) {
		cin >> a >> b;
		a--;b--;
		T[a].push_back(b);
		T[b].push_back(a);
	}
	fdfs(0, 512411, 0);
	sdfs(fen, snu);
	int fc = cnt;
	cnt = 0;
	sdfs(snu, fen);
	int sc = cnt;
	//cout << fc << "," << sc << endl;
	if (sc < fc)
		cout << "Fennec" << endl;
	else
		cout << "Snuke" << endl;
}