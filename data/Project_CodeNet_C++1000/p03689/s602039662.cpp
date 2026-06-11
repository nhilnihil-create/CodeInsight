#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>

using namespace std;

const int mxx = 100000;

int H, W, h, w;

int main() {
	scanf("%d%d%d%d", &H, &W, &h, &w);
	if (!(H % h) && !(W % w)) {
		puts("No");
		return 0;
	}
	puts("Yes");
	if (H % h) {
		for (int i = 0; i < H; ++i) {
			for (int j = 1; j <= W; ++j) {
				if (i % h) { printf("%d ", -mxx); }
				else { printf("%d ", mxx * (h - 1) - 1); }
			}
			puts("");
		}
	}
	else {
		for (int i = 1; i <= H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (j % w) { printf("%d ", -mxx); }
				else { printf("%d ", mxx * (w - 1) - 1); }
			}
			puts("");
		}
	}
	return 0;
}
