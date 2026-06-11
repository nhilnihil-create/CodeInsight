#include <cstdio>
const char map[4] = {'R', 'Y', 'G', 'B'};
int H, W, d, x, y;
int main() {
	scanf("%d %d %d", &H, &W, &d);
	for(int i = 1; i <= H; ++i) {
		for(int j = 1; j <= W; ++j) {
			x = (i + j + W) / d, y = (i - j + W) / d;
			putchar(map[((x&1)<<1) | (y&1)]);
		}
		putchar('\n');
	}
	return 0;
}