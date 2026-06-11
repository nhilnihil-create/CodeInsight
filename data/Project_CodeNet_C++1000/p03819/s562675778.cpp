#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, L[300009], R[300009], bit[300009], num[300009];
vector<int>x[100009];
vector<pair<int, int>>G[300009];

void add(int pos, int x) {
	while (pos <= N) {
		bit[pos] += x; pos += (pos&-pos);
	}
}
int sum(int pos) {
	int s = 0;
	while (pos >= 1) { s += bit[pos]; pos -= (pos&-pos); }
	return s;
}

int main() {
	cin >> K >> N;
	for (int i = 1; i <= K; i++) {
		cin >> L[i] >> R[i];
		G[L[i]].push_back(make_pair(1, i));
		G[R[i]].push_back(make_pair(2, i));
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j += i) x[j].push_back(i);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < G[i].size(); j++) { if (G[i][j].first == 2) continue; add(i, 1); }

		for (int j : x[i]) {
			int v1 = i - j, v2 = i;
			int F = sum(v2) - sum(v1);
			num[j] += F;
		}

		for (int j = 0; j < G[i].size(); j++) { if (G[i][j].first == 1) continue; add(L[G[i][j].second], -1); }
	}
	for (int i = 1; i <= N; i++) cout << num[i] << endl;
	return 0;
}