#include <iostream>
#include <cstdio>
#define N 505
using namespace std;

int H, W, h, w, a[N][N];
int main()
{
	int i, j;
	cin >> H >> W >> h >> w;
	if (H % h == 0 && W % w == 0) {cout << "No"; return 0;}
	cout << "Yes" << endl;
	if (H % h) {
		for (i = 0; i < H; i++) {
			for (j = 0; j < W; j++) a[i][j] = i % h ? -1000 : 1000 * h - 1001;
		}
	} else {
		for (i = 0; i < W; i++) {
			for (j = 0; j < H; j++) a[j][i] = i % w ? -1000 : 1000 * w - 1001;
		}
	}
	for (i = 0; i < H; i++, puts("")) for (j = 0; j < W; j++) printf("%d ", a[i][j]);
    return 0;
}