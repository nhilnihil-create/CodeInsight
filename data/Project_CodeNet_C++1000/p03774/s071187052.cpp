#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	int a[50], b[50], c[50], d[50];
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &c[i], &d[i]);
	}
	for (int i = 0; i < N; i++) {
		int nearest = 2000000000;
		int ans;
		for (int j = 0; j < M; j++) {
			int dis = abs(a[i] - c[j]) + abs(b[i] - d[j]);
			if (dis < nearest) {
				nearest = dis;
				ans = j + 1;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
