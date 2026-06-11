#include<cstdio>
const static int MAX_H = 100;
const static int MAX_W = 100;
int color[MAX_H][MAX_W];
int H, W, N;

int NextX(int x, int y){
	if(x & 1){
		if(y) return x;
		return x + 1;
	}
	if(y < W - 1) return x;
	return x + 1;
}

int NextY(int x, int y){
	if(x & 1){
		if(y) return y - 1;
		return y;
	}
	if(y < W - 1) return y + 1;
	return y;
}

int main(){
	scanf("%d %d\n%d", &H, &W, &N);
	int x = 0, y = -1;
	for (int i = 0; i < N; ++i){
		int a;
		scanf("%d", &a);
		for (int j = 0; j < a; ++j){
			int _x = x;
			color[x = NextX(_x, y)][y = NextY(_x, y)] = i+1;
		}
	}
	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			if(j) printf(" ");
			printf("%d", color[i][j]);
		}
		printf("\n");
	}
	return 0;
}