#include <bits/stdc++.h>
using namespace std;

const int maxN = 410;

char str[maxN][maxN];

int main (){
	int h, w, i, j;
	scanf("%d%d", &h, &w);
	for(i = 1; i <= h; ++i) scanf("%s", str[i] + 1);
	for(i = 1; i <= h + h; ++i){
		for(j = 1; j <= w; ++j)
			printf("%c", str[(i + 1) / 2][j]);
		puts("");
	}
	return 0;
}
