#include "bits/stdc++.h"
using namespace std;

int N, INF = 1000000000;
static int Dis1[100010] = {}, DisN[100010] = {};
vector<int> V[100010];

void BFS1() {
	for (int i = 1; i < N; i++) {
		Dis1[i] = INF;
	}
	queue<int> Q;
	Q.push(0);
	while (Q.size()) {
		int x = Q.front();
		Q.pop();
		for (int i : V[x]) {
			if (Dis1[i] == INF) {
				Q.push(i);
				Dis1[i] = Dis1[x] + 1;
			}
		}
	}
}

void BFSN() {
	for (int i = 0; i < N - 1; i++) {
		DisN[i] = INF;
	}
	queue<int> Q;
	Q.push(N - 1);
	while (Q.size()) {
		int x = Q.front();
		Q.pop();
		for (int i : V[x]) {
			if (DisN[i] == INF) {
				Q.push(i);
				DisN[i] = DisN[x] + 1;
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		V[a].emplace_back(b);
		V[b].emplace_back(a);
	}
	BFS1();
	BFSN();
	int F = 0, S = 0;
	for (int i = 0; i < N; i++) {
		if (Dis1[i] <= DisN[i]) F++;
		else S++;
	}
	if (F > S) cout << "Fennec";
	else cout << "Snuke";
}