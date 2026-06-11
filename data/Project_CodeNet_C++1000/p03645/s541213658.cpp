#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int N, M, A[1 << 18], B[1 << 18];
int c1[1 << 18], c2[1 << 18];
vector<int> X[1 << 18];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		X[A[i]].push_back(B[i]);
		X[B[i]].push_back(A[i]);
	}
	for (int i : X[1]) c1[i] = 1;
	for (int i : X[N]) c2[i] = 1;
	for (int i = 1; i <= N; i++) {
		if (c1[i] + c2[i] == 2) { cout << "POSSIBLE" << endl; return 0; }
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}