#include "bits/stdc++.h"
using namespace std;

int N, K, Dis[2000], INF = 1145141919;
vector<int> V[2000];
pair<int, int> P[2000];

void DFS(int p, int r) {
	for (int x : V[p]) {
		if (Dis[x] == INF) {
			Dis[x] = r + 1;
			DFS(x, r + 1);
		}
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		int A, B;
		cin >> A >> B;
		A--, B--;
		P[i] = { A, B };
		V[A].push_back(B);
		V[B].push_back(A);
	}
	if (K % 2 == 0) {
		int ANS = N;
		for (int i = 0; i < N; i++) {
			int COUNT = 0;
			for (int j = 0; j < N; j++) Dis[j] = INF;
			Dis[i] = 0;
			DFS(i, 0);
			for (int j = 0; j < N; j++) {
				if (Dis[j] * 2 > K) COUNT++;
			}
			ANS = min(ANS, COUNT);
		}
		cout << ANS;
		return 0;
	}
	else {
		int ANS = N;
		for (int i = 0; i < N - 1; i++) {
			int COUNT = 0;
			for (int j = 0; j < N; j++) Dis[j] = INF;
			Dis[P[i].first] = 0;
			Dis[P[i].second] = 0;
			DFS(P[i].first, 0);
			DFS(P[i].second, 0);
			for (int j = 0; j < N; j++) {
				if (Dis[j] * 2 > K - 1) COUNT++;
			}
			ANS = min(ANS, COUNT);
		}
		cout << ANS;
		return 0;
	}
}