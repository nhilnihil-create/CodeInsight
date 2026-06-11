#include <bits/stdc++.h>
using namespace std;

int num[505][505];

int main(){
	int a, b, w, h;
	long long sum;
	scanf("%d %d %d %d",&b,&a,&h,&w);
	memset(num, 0, sizeof(num));
	for (int i = 1; i <= b / h; i++){
		for (int j = 1; j <= a / w; j++){
			num[i * h][j * w] = -(w * h - 1) * 3000 - 1;
		}
	}
	sum = 0;
	for (int i = 1; i <= b; i++){
		for (int j = 1; j <= a; j++){
			if (!num[i][j]) num[i][j] = 3000;
			sum += num[i][j];
		}
	}
	if (sum <= 0) printf("No\n");
	else{
		printf("Yes\n");
		for (int i = 1; i <= b; i++){
			for (int j = 1; j <= a; j++){
				printf("%d", num[i][j]);
				if (j < a) printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
} 