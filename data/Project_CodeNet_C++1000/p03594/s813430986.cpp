#include <iostream>

using namespace std;

int H, W, d;
int mat[505][505];
char col[] = {'R', 'B', 'Y', 'G'};

int main(void)
{
	cin >> H >> W >> d;
	
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			if( ((i + j) / d) % 2 ) mat[i][j] |= 1;
		}
	}
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
		if( ((i + j) / d) % 2 ) mat[(H-1)-i][j] |= 2;
		}
	}
	
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cout << col[mat[i][j]];
		}
		cout << endl;
	}
	
	return 0;
}