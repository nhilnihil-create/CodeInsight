#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

int H, W, d;
char HW[501][501];
#define OFFSET (502)

struct ToHW {
	int x;
	int y;
};
ToHW linkHW[1010][1010];


// HW
// 1 2 3 
// 4 5 6
// 7 8 9

// hw
//     1
//   4   2
// 7   5   3
//   8   6
//     9

int main(void)
{
	cin >> H >> W >> d;
	memset(HW, 0, sizeof(HW));

	for (int x = 0; x < 1010; x++) {
		for (int y = 0; y < 1010; y++) {
			linkHW[x][y].x = -1;
			linkHW[x][y].y = -1;
		}
	}

	int cnt = 0;
	for (int x = 0; x < W; x++) {
		for (int y = 0; y < H; y++) {
			int nx = OFFSET + x - y;
			int ny = x + y;
			linkHW[nx][ny].x = x;
			linkHW[nx][ny].y = y;
		}
	}

	int paint1 = 0;
	int paint2 = 0;
	for (int sx = 0; sx < 1010; sx+= d) {
		paint1 ^= 1;
		for (int sy = 0; sy < 1010; sy+= d) {
			paint2 ^= 1;
			for (int x = sx; x < sx+d; x++) {
				for (int y = sy; y < sy+d; y++) {
					if (x>=1010) continue;
					if (y>=1010) continue;
					int ox = linkHW[x][y].x;
					int oy = linkHW[x][y].y;
					if ((ox >= 0) && (oy >= 0)) {
						int paint = (paint1 << 1) + paint2;
						char color;
						switch(paint) {
							case 0: color = 'R'; break;
							case 1: color = 'B'; break;
							case 2: color = 'G'; break;
							case 3: color = 'Y'; break;
						}
						HW[ox][oy] = color;
					}
				}
			}
		}
	}

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cout << HW[x][y];
		}
		cout << endl;
	}

	return 0;
}
