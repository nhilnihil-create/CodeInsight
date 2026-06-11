#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
};

int getDist(Point p1, Point p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

#define MAX 50

int main() {
	int N, M;
	Point S[MAX], C[MAX];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		S[i] = Point { x, y };
	}
	for (int j = 0; j < M; j++) {
		int x, y;
		cin >> x >> y;
		C[j] = Point { x, y };
	}
	for (int i = 0; i < N; i++) {
		Point s = S[i];
		int ans = -1;
		int mindist = INT_MAX;
		for (int j = 0; j < M; j++) {
			if (getDist(s, C[j]) < mindist) {
				mindist = getDist(s, C[j]);
				ans = j;
			}
		}
		cout << ans + 1 << endl;
	}
	return 0;
}
