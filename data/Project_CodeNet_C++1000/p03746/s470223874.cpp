#include "bits/stdc++.h"
using namespace std;

int N, M;
vector<int> V[100000];
deque<int> ANS;
bool visit[100000] = {};

void DFS1(int P) {
	visit[P] = true;
	for (int Q : V[P]) {
		if (!visit[Q]) {
			ANS.push_back(Q);
			DFS1(Q);
			return;
		}
	}
}

void DFS2(int P) {
	visit[P] = true;
	for (int Q : V[P]) {
		if (!visit[Q]) {
			ANS.push_front(Q);
			DFS2(Q);
			return;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		A--, B--;
		V[A].push_back(B);
		V[B].push_back(A);
	}
	ANS.push_back(0);
	DFS1(0), DFS2(0);
	cout << ANS.size() << endl;
	while (ANS.size()) {
		cout << ANS.front() + 1;
		ANS.pop_front();
		if (ANS.size()) cout << " ";
	}
}