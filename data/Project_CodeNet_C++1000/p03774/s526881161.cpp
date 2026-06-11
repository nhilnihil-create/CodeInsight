#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int N, M;
int A[1 << 18], B[1 << 18], C[1 << 18], D[1 << 18];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];
	for (int i = 1; i <= M; i++) cin >> C[i] >> D[i];
	for (int i = 1; i <= N; i++) {
		int minx = (1 << 30), minid = -1;
		for (int j = 1; j <= M; j++) {
			int dst = abs(A[i] - C[j]) + abs(B[i] - D[j]);
			if (minx > dst) { minx = dst; minid = j; }
		}
		cout << minid << endl;
	}
	return 0;
}