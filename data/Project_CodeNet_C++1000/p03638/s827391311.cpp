#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

#include <inttypes.h>
using namespace std;

int main()
{
	int32_t H, W, N;
	scanf("%d%d%d", &H, &W, &N);

	int32_t colors[10000];
	memset(colors, 0, sizeof(colors));
	int32_t color_index = 0;
	for (int32_t i = 0; i < N; i++) {
		int32_t a;
		scanf("%d", &a);
		for (int32_t j = 0; j < a; j++) {
			colors[color_index++] = i + 1;
		}
	}

	int32_t res[100][100];
	color_index = 0;
	for (int32_t row = 0; row < H; row++) {
		if (row % 2 == 0) {
			for (int32_t col = 0; col < W; col++) {
				res[row][col] = colors[color_index++];
			}
		} else {
			for (int32_t col = W - 1; col >= 0; col--) {
				res[row][col] = colors[color_index++];
			}
		}
	}

	for (int32_t row = 0; row < H; row++) {
		for (int32_t col = 0; col < W; col++) {
			printf("%d", res[row][col]);
			if (col < W - 1)
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}