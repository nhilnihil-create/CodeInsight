#include <bits/stdc++.h>

#define For(i, j, k) for(int i = j; i <= k; i++)

using namespace std;

const int N = 510;

int H, W, h, w;
int ans[N][N];

int main(){
	scanf("%d%d%d%d", &H, &W, &h, &w);
	
	int cx = H / h, cy = W / w;
	int sum = H * W - cx * cy * h * w;
	int C = 1e8 / (h * w);

	if(sum <= 0){
		puts("No");
		return 0;
	}

	puts("Yes");
	For(i, 1, H) For(j, 1, W) ans[i][j] = C;
	For(i, 1, cx) For(j, 1, cy) ans[i * h][j * w] = -(h * w - 1) * C - 1;

	For(i, 1, H) For(j, 1, W) printf("%d%c", ans[i][j], j == W ? '\n' : ' ');
	return 0;
}